#include<stdio.h> 
#include <bits/stdc++.h> 
using namespace std; 
vector<vector<int> > graph; 
map<pair<int, int>, int> cost;
vector<int> uniform_cost_search(vector<int> goal, int start)
{
vector<int> answer; priority_queue<pair<int, int> > queue;
for (int i = 0; i < goal.size(); i++)
answer.push_back(INT_MAX);
queue.push(make_pair(0, start)); map<int, int> visited; int count = 0; 
while (queue.size() > 0) 
{ 
pair<int, int> p = queue.top(); 
queue.pop();
p.first *= -1; 
if (find(goal.begin(), goal.end(), p.second) != goal.end()) 
{
int index = find(goal.begin(), goal.end(),p.second) - goal.begin();
if (answer[index] == INT_MAX) count++;
if (answer[index] > p.first) answer[index] = p.first; queue.pop();
if (count == goal.size()) return answer;
}
if (visited[p.second] == 0) 
for (int i = 0; i < graph[p.second].size(); i++) 
{ 
queue.push(make_pair((p.first + cost[make_pair(p.second, graph[p.second][i])]) * -1, graph[p.second][i]));
}
visited[p.second] = 1;
}
return answer;
}
int main()
{
graph.resize(4);
graph[0].push_back(1); 
graph[0].push_back(2); 
graph[1].push_back(2); 
graph[2].push_back(0); 
graph[2].push_back(3); 
graph[3].push_back(3);
cost[make_pair(0, 1)] = 2; 
cost[make_pair(0, 2)] = 5; 
cost[make_pair(1, 2)] = 1; 
cost[make_pair(2, 0)] = 5; 
cost[make_pair(2, 3)] = 6; 
cost[make_pair(3, 3)] = 2; 
vector<int> goal; 
goal.push_back(3); 
vector<int> answer = uniform_cost_search(goal, 0); 
cout << "Minimum cost from 0 to 3 is = "<< answer[0] << endl;
return 0;
}
