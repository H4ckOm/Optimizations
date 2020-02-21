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
        self.books = books
        #
        self.books.sort(key = lambda x: bs[x], reverse=True)
        # self.compute_score_for_n_days()
    def compute_score_for_n_days(self):
        # save a metric for each n, how many points this library can score in isolation
        # given n days.  KEY word being "in isolation" as the difficulty of the problem
        # comes from multiple libraries having the same book.
        #
        # future improvements: score a book on how ill-represented it is, amongst the top libraries perhaps
        self.pre = [0] # with 0 days left, we can't do anything
        for i in range(D):
            # book_score = bs[self.books[i]] if i < len(self.books) else 0
            if i < len(self.books):
               self.pre.append(self.pre[-1] + bs[self.books[i]])
            else:
                break
    def get_score_for_n_days(self, n):
        if n < len(self.pre):
            return self.pre[n]
        else:
            return self.pre[-1]
    def get_score_for_n_days_except_given_books(self, n, books):
        # if I can't have these books, how well can I score?
        book_count = 0
        ans = 0
        for b in self.books:
            if b in books:
                continue
            ans += bs[b]
            book_count += 1
            if book_count == n:
                break
        return ans
    def total_book_score(self):
        return sum([bs[b] for b in self.books])

B, L, D = map(int, input().split())
bs = [int(x) for x in input().split()]
ls = []
for l_id in range(L):
    n, t, m = map(int, input().split())
    books = [int(x) for x in input().split()]
    l = Lib(l_id, n, t, m, books)
    ls.append(l)
    print(l_id, l.total_book_score(), len(l.books))
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
        self.lib_set.add(l)
    def add(self, l, b):
        self.lb[l].add(b)
        self.books.add(b)
    def score(self):
        return sum(bs[b] for b in self.books)
    def str(self):
        ans = ''
        ans += '{}\n'.format(len(self.libs))
        for l in self.libs:
            ans += '{} {}\n'.format(l, len(self.lb[l]))
            ans += '{}\n'.format(' '.join([str(x) for x in self.lb[l]]))
        return ans

ITERATIONS = 100
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
        sol = Sol()
        d = 0
        random.shuffle(ls)
        while True:
            days_left = D - d
            # pick the next library
            if d == 0:
                best_lib = ls[0]
            else:
                best_lib = None
                bl_score = 0
                for l in ls:
                    if l.id in sol.lib_set:
                        continue
                    # my_score = l.get_score_for_n_days(days_left)
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
            sol.add_l(l.id)
            # done adding the next lib.  now add books for it.
            books_added = 0
            for book in l.books:
                if books_added == days_left:
                    break
                if book not in sol.books:
                    sol.add(l.id, book)
                    books_added += 1
            #hack to avoid empty line
            if books_added == 0:
                sol.add(l.id, l.books[0])
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
main()
