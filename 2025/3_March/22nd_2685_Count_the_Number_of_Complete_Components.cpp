#include <bits/stdc++.h>
using namespace std;

class Solution
{
  void dfs(int node, int &nodeCount, int &edgeCount, vector<vector<int>> &adj, vector<int> &vis)
  {
    vis[node] = 1;
    nodeCount++;

    for (int adjNode : adj[node])
    {
      edgeCount++;

      if (!vis[adjNode])
        dfs(adjNode, nodeCount, edgeCount, adj, vis);
    }
  }

public:
  int countCompleteComponents(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> adj(n);

    for (auto edge : edges)
    {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> vis(n, 0);
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      int nodeCount = 0, edgeCount = 0;

      if (!vis[i])
      {
        dfs(i, nodeCount, edgeCount, adj, vis);

        if (edgeCount == nodeCount * (nodeCount - 1))
          result++;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;

  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};

  cout << sol.countCompleteComponents(n, edges);

  return 0;
}