#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void solve(vector<vector<int>> &adj, vector<int> &targets, int k)
  {
    int n = adj.size();

    for (int i = 0; i < n; i++)
    {
      queue<int> q;
      vector<int> vis(n, 0);

      q.push(i);

      int depth = k + 1;

      while (depth--)
      {
        int size = q.size();
        targets[i] += size;

        for (int k = 0; k < size; k++)
        {
          int node = q.front();
          q.pop();

          vis[node] = 1;

          for (int adjNode : adj[node])
          {
            if (!vis[adjNode])
              q.push(adjNode);
          }
        }
      }
    }
  }

  vector<int> maxTargetNodesBrute(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
  {
    int n = edges1.size() + 1, m = edges2.size() + 1;

    vector<vector<int>> adj1(n), adj2(m);

    for (auto it : edges1)
    {
      int u = it[0], v = it[1];

      adj1[u].push_back(v);
      adj1[v].push_back(u);
    }

    for (auto it : edges2)
    {
      int u = it[0], v = it[1];

      adj2[u].push_back(v);
      adj2[v].push_back(u);
    }

    vector<int> treeOne(n, 0);

    solve(adj1, treeOne, k);

    if (k == 0)
      return treeOne;

    vector<int> treeTwo(m, 0);

    solve(adj2, treeTwo, k - 1);

    int maxNodeTreeTwo = *max_element(treeTwo.begin(), treeTwo.end());

    for (int i = 0; i < n; i++)
      treeOne[i] += maxNodeTreeTwo;

    return treeOne;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}},
                      edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};
  int k = 2;

  auto ans = sol.maxTargetNodesBrute(edges1, edges2, k);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}