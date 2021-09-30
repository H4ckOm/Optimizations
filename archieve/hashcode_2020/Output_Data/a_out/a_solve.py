# Omkar Deshmukh
from collections import defaultdict
import random
import sys
import json

class Lib:
    # represents a library in the input
    def __init__(self, id, n, d, m, books):
        self.id = id
        self.n = n
        self.d = d
        self.m = m
        #assert len(books) == len(set(books)) #rm this later for performance?
        self.book_set = set(books)
        self.books = books
        self.books.sort(key = lambda x: book_scorer.get_score(x))
        self.books.reverse()
        self.compute_score_for_n_days()
        
    def compute_score_for_n_days(self):
        # save a metric for each n, how many points this library can score in isolation
        # given n days.  KEY word being "in isolation" as the difficulty of the problem
        # comes from multiple libraries having the same book.
        #
        # future improvements: score a book on how ill-represented it is, amongst the top libraries perhaps
        self.pre = [0] # with 0 days left, we can't do anything
        for i in range(D):
            if i < len(self.books):
               self.pre.append(self.pre[-1] + book_scorer.get_score(self.books[i]))
            else:
                break
                
    def get_score_for_n_days(self, n):
        if n < len(self.pre):
            return self.pre[n]
        else:
            return self.pre[-1]
        
    def resort_books(self):
        self.books.sort(key = lambda x: book_scorer.get_score(x))
        self.books.reverse()
        
    def get_score_for_n_days_except_given_books(self, n, books):
        # if I can't have these books, how well can I score?
        book_count = 0
        ans = 0
        for b in self.books:
            if b in books:
                continue
            ans += book_scorer.get_score(b)
            book_count += 1
            if book_count == n * self.m:
                break
        return ans
    
    def total_book_score(self):
        return sum([book_scorer.get_score(b) for b in self.books])

class BookScorer:
    
    def __init__(self):
        self.scores = bs
        
    def update_with_libs(self, libs):
        book_count = defaultdict(int)
        for l in libs:
            for book in l.books:
                book_count[book] += 1
        self.scores = dict()
        for book in book_count:
            self.scores[book] = bs[book]# * (0.5 * 1/book_count[book] + 0.5)
            
    def update_with_books(self, books):
        for b in range(len(bs)):
            if b not in books:
                self.scores[b] = bs[b]
                
    def get_score(self, book):
        # if self.scores[book] != bs[book]:
        #     print(book, self.scores[book], bs[book])
        return self.scores[book]

    
rl = lambda: list(map(int,input().split()))
B, L, D = rl()

bs = rl()

book_scorer = BookScorer()

ls = []

for l_id in range(L):
    n, t, m = rl()
    books = rl()
    l = Lib(l_id, n, t, m, books)
    ls.append(l)
    print(l_id, l.total_book_score(), len(l.books), l.n, l.d, l.m)
    # print(l.pre)

class Sol:
    # solution class (can output the score and the output string)
    def __init__(self):
        self.libs = []
        self.lib_set = set()
        self.lb = defaultdict(set)
        self.books = set()
        
    def add_l(self, l):
        self.libs.append(l)
        self.lib_set.add(l.id)
        
    def add(self, l, b):
        self.lb[l].add(b)
        self.books.add(b)
    
    def score(self):
        return sum(bs[b] for b in self.books)
    
    def str(self):
        ans = ''
        ans += '{}\n'.format(len(self.libs))
        for l in self.libs:
            ans += '{} {}\n'.format(l.id, len(self.lb[l.id]))
            ans += '{}\n'.format(' '.join([str(x) for x in self.lb[l.id]]))
        return ans

ITERATIONS = 100
P = 0.1
def main():
    # run like
    # > python3 main.py a < a.txt
    if len(sys.argv) <= 1:
        raise ValueError("must give argument for dataset")
    dataset = sys.argv[1]
    if dataset not in 'abcdef':
        raise ValueError("arg must be abcdef")
    its = ITERATIONS
    if len(sys.argv) >= 3:
        its = int(sys.argv[2])
    with open('scores.json', 'r') as f:
        scores = json.load(f)
    if dataset not in scores:
        scores[dataset] = 0
    print('prev high score: {}'.format(scores[dataset]))

    for i in range(its):
        # randomly disallow a certain number of libs
        dropout = random.sample(range(len(ls)), int(P*len(ls)))
        #dropout = []
        for l in ls:
            l.resort_books()
            #l.compute_score_for_n_days()
        sol = Sol()
        d = 0
        random.shuffle(ls)
        while True:
            days_left = D - d
            # pick the next library
            best_lib = None
            bl_score = 0
            for l in ls:
                if l.id in sol.lib_set or l.id in dropout:
                    continue
                #my_score = l.get_score_for_n_days(days_left)
                my_score = l.get_score_for_n_days_except_given_books(days_left-l.d, sol.books)# * random.uniform(0.99, 1/0.99)
                if my_score > bl_score:
                    best_lib = l
                    bl_score = my_score
            l = best_lib
            if l is None:
                break
            # done picking the next lib.  now add it.
            # print("best lib is", l.id, "with score of", bl_score)
            d += l.d
            days_left = D - d
            if days_left <= 0:
                break
            sol.add_l(l)
            # done adding the next lib.  now add books for it.
            books_added = 0
            for book in l.books:
                if books_added == days_left * l.m:
                    break
                if book not in sol.books:
                    sol.add(l.id, book)
                    books_added += 1
            #hack to avoid empty line
            if books_added == 0:
                sol.add(l, l.books[0])
            #end hack
        print("score is", sol.score())
        # print("===printing output===", sol.str(), sep='\n')
        if sol.score() > scores[dataset]:
            print("score is higher than prev! writing...")
            with open('{}_out.txt'.format(dataset), 'w') as f:
                f.write(sol.str())
            scores[dataset] = sol.score()
            with open('scores.json', 'w') as f:
                json.dump(scores, f)
            print("done writing")

        # based on this run, re-evaluate how important certain books are
        book_scorer.update_with_libs(sol.libs)
        book_scorer.update_with_books(sol.books)

main()
