#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<long long, long long> P;
  int MOD = 1e9 + 7;

  int countPaths(int n, vector<vector<int>> &roads)
  {
    vector<vector<P>> adj(n);

    for (auto road : roads)
    {
      int u = road[0];
      int v = road[1];
      int wt = road[2];

      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    vector<long long> dist(n, LONG_LONG_MAX);
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<long long> result(n, 0);

    dist[0] = 0;
    pq.push({0, 0});

    result[0] = 1;

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();

      int node = top.second;
      long long currDist = top.first;

      for (auto ngbr : adj[node])
      {
        int adjNode = ngbr.first;
        long long edgeWt = ngbr.second;

        long long newDist = currDist + edgeWt;

        if (newDist < dist[adjNode])
        {
          dist[adjNode] = newDist;
          pq.push({newDist, adjNode});

          result[adjNode] = result[node];
        }

        else if (newDist == dist[adjNode])
          result[adjNode] = (result[adjNode] + result[node]) % MOD;
      }
    }

    return result[n - 1];
  }
};

int main()
{
  Solution sol;

  int n = 7;
  vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}};

  cout << sol.countPaths(n, roads);

  return 0;
}