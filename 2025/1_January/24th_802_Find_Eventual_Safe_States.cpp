#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSafe(int node, vector<vector<int>> &graph, vector<int> &vis,
              vector<int> &pathVis, vector<int> &safeNode)
  {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto adjNode : graph[node])
    {
      if (!vis[adjNode])
      {
        if (!isSafe(adjNode, graph, vis, pathVis, safeNode))
          return false;
      }
      else if (pathVis[adjNode])
        return false;
    }

    pathVis[node] = 0;
    safeNode[node] = 1;

    return true;
  }

  vector<int> eventualSafeNodesDFS(vector<vector<int>> &graph)
  {
    int n = graph.size();

    vector<int> vis(n, 0), pathVis(n, 0), safeNode(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
        isSafe(i, graph, vis, pathVis, safeNode);
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      if (safeNode[i])
        result.push_back(i);
    }

    return result;
  }

  vector<int> eventualSafeNodesBFS(vector<vector<int>> &graph)
  {
    int n = graph.size();

    vector<vector<int>> adj(n);

    for (int node = 0; node < n; node++)
    {
      for (auto adjNode : graph[node])
        adj[adjNode].push_back(node);
    }

    vector<int> indeg(n, 0);

    for (int node = 0; node < n; node++)
    {
      for (auto adjNode : adj[node])
        indeg[adjNode]++;
    }

    queue<int> q;

    for (int node = 0; node < n; node++)
    {
      if (indeg[node] == 0)
        q.push(node);
    }

    vector<int> safeNode(n, 0);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      safeNode[node] = 1;

      for (int adjNode : adj[node])
      {
        indeg[adjNode]--;

        if (indeg[adjNode] == 0)
          q.push(adjNode);
      }
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      if (safeNode[i])
        result.push_back(i);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

  auto ans = sol.eventualSafeNodesBFS(graph);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.eventualSafeNodesDFS(graph);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}