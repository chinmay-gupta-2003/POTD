#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
  {
    vector<vector<pair<int, double>>> adjList(n);

    for (int i = 0; i < edges.size(); i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      double prob = succProb[i];

      adjList[u].push_back({v, prob});
      adjList[v].push_back({u, prob});
    }

    vector<double> probability(n, 0);
    priority_queue<pair<double, int>> pq;

    probability[start_node] = 1;
    pq.push({1, start_node});

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();

      int currNode = top.second;
      double currProbability = top.first;

      for (auto adjNode : adjList[currNode])
      {
        double newProbability = currProbability * adjNode.second;

        if (newProbability > probability[adjNode.first])
        {
          probability[adjNode.first] = newProbability;
          pq.push({newProbability, adjNode.first});
        }
      }
    }

    return probability[end_node];
  }
};

int main()
{
  Solution sol;

  int n = 3;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
  vector<double> succProb = {0.5, 0.5, 0.2};
  int start_node = 0, end_node = 2;

  cout << sol.maxProbability(n, edges, succProb, start_node, end_node);

  return 0;
}