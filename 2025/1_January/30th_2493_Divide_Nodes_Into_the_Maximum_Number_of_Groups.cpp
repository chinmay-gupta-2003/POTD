#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkBipartite(int node, int nodeColor, vector<int> &color,
                      vector<vector<int>> &adj)
  {
    color[node] = nodeColor;

    for (auto adjNode : adj[node])
    {
      if (color[adjNode] == -1)
      {
        if (!checkBipartite(adjNode, !nodeColor, color, adj))
          return false;
      }
      else if (color[adjNode] == nodeColor)
        return false;
    }

    return true;
  }

  int bfs(int node, vector<vector<int>> &adj, int n)
  {
    queue<int> q;
    vector<int> vis(n, 0);

    q.push(node);
    vis[node] = 1;

    int level = 0;

    while (!q.empty())
    {
      int size = q.size();
      level++;

      while (size--)
      {
        int front = q.front();
        q.pop();

        for (int adjNode : adj[front])
        {
          if (!vis[adjNode])
          {
            q.push(adjNode);
            vis[adjNode] = 1;
          }
        }
      }
    }

    return level;
  }

  int dfs(int node, vector<vector<int>> &adj, vector<int> &nodeGroups, vector<int> &vis)
  {
    vis[node] = 1;

    int maxGroup = nodeGroups[node];

    for (int adjNode : adj[node])
    {
      if (!vis[adjNode])
        maxGroup = max(maxGroup, dfs(adjNode, adj, nodeGroups, vis));
    }

    return maxGroup;
  }

  int magnificentSets(int n, vector<vector<int>> &edges)
  {
    vector<vector<int>> adj(n);

    for (auto it : edges)
    {
      int u = it[0] - 1;
      int v = it[1] - 1;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> colors(n, -1);

    for (int i = 0; i < n; i++)
    {
      if (colors[i] == -1 && !checkBipartite(i, 0, colors, adj))
        return -1;
    }

    vector<int> nodeGroups(n, 0);

    for (int i = 0; i < n; i++)
      nodeGroups[i] = bfs(i, adj, n);

    int result = 0;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
        result += dfs(i, adj, nodeGroups, vis);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int n = 6;
  vector<vector<int>> edges = {{1, 2}, {1, 4}, {1, 5}, {2, 6}, {2, 3}, {4, 6}};

  cout << sol.magnificentSets(n, edges);

  return 0;
}