#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> parent, size;

  DisjointSet(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int FindParent(int node)
  {
    if (parent[node] == node)
      return node;

    return parent[node] = FindParent(parent[node]);
  }

  void UnionBySize(int u, int v)
  {
    int parent_u = FindParent(u), parent_v = FindParent(v);

    if (parent_u == parent_v)
      return;

    if (size[parent_u] > size[parent_v])
    {
      parent[parent_v] = parent_u;
      size[parent_u] += size[parent_v];
    }
    else
    {
      parent[parent_u] = parent_v;
      size[parent_v] += size[parent_u];
    }
  }
};

class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    int n = edges.size();

    DisjointSet DS(n);

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];

      if (DS.FindParent(u) == DS.FindParent(v))
        result = {u, v};
      else
        DS.UnionBySize(u, v);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};

  auto ans = sol.findRedundantConnection(edges);

  cout << ans[0] << " " << ans[1];

  return 0;
}