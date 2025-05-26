#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isCycle(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis)
  {
    vis[node] = 1;
    pathVis[node] = 1;

    for (int adjNode : adj[node])
    {
      if (!vis[adjNode])
      {
        if (isCycle(adjNode, adj, vis, pathVis))
          return true;
      }
      else if (pathVis[adjNode])
        return true;
    }

    pathVis[node] = 0;

    return false;
  }

  void solve(int node, string &colors, vector<vector<int>> &adj, unordered_map<char, int> &freqMap, vector<int> &vis, int &result)
  {
    vis[node] = 1;
    freqMap[colors[node]]++;

    for (int adjNode : adj[node])
      solve(adjNode, colors, adj, freqMap, vis, result);

    for (auto it : freqMap)
      result = max(result, it.second);

    freqMap[colors[node]]--;
  }

  int largestPathValueBrute(string colors, vector<vector<int>> &edges)
  {
    int n = colors.size();
    vector<vector<int>> adj(n);

    for (auto it : edges)
    {
      int u = it[0], v = it[1];

      adj[u].push_back(v);
    }

    int result = -1;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        unordered_map<char, int> freqMap;

        vector<int> cycleVis(n, 0), pathVis(n, 0);
        if (isCycle(i, adj, cycleVis, pathVis))
          continue;

        solve(i, colors, adj, freqMap, vis, result);
      }
    }

    return result;
  }

  int largestPathValueOptimal(string colors, vector<vector<int>> &edges)
  {
    int n = colors.size();

    vector<int> indegree(n, 0);
    vector<vector<int>> adj(n);

    for (auto it : edges)
    {
      int u = it[0], v = it[1];

      adj[u].push_back(v);
      indegree[v]++;
    }

    queue<int> q;
    vector<vector<int>> colorMap(n, vector<int>(26, 0));

    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
        colorMap[i][colors[i] - 'a'] = 1;
      }
    }

    int count = 0, result = 0;

    while (!q.empty())
    {
      int top = q.front();
      q.pop();

      result = max(result, colorMap[top][colors[top] - 'a']);

      count++;

      for (int adjNode : adj[top])
      {
        int nodeColor = colors[top] - 'a';
        int adjNodeColor = colors[adjNode] - 'a';

        for (int i = 0; i < 26; i++)
          colorMap[adjNode][i] = max(colorMap[adjNode][i], colorMap[top][i] + (adjNodeColor == i));

        indegree[adjNode]--;
        if (indegree[adjNode] == 0)
          q.push(adjNode);
      }
    }

    return count < n ? -1 : result;
  }
};

int main()
{
  Solution sol;

  string colors = "abaca";
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};

  cout << sol.largestPathValueBrute(colors, edges) << endl;

  return 0;
}