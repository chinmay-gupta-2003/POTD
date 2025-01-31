#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> size, parent;

  DisjointSet(int n)
  {
    size.resize(n);
    parent.resize(n);

    for (int i = 0; i < n; i++)
    {
      size[i] = 1;
      parent[i] = i;
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
    int parent_u = FindParent(u);
    int parent_v = FindParent(v);

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
  int largestIsland(vector<vector<int>> &grid)
  {
    int n = grid.size();

    DisjointSet ds(n * n);

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
        {
          for (auto coords : directions)
          {
            int i_ = i + coords[0];
            int j_ = j + coords[1];

            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_])
              ds.UnionBySize(i * n + j, i_ * n + j_);
          }
        }
      }
    }

    int result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!grid[i][j])
        {
          unordered_set<int> adjNodes;

          int size = 1;

          for (auto coords : directions)
          {
            int i_ = i + coords[0];
            int j_ = j + coords[1];

            if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_])
              adjNodes.insert(ds.FindParent(i_ * n + j_));
          }

          for (int node : adjNodes)
            size += ds.size[node];

          result = max(result, size);
        }
      }
    }

    return result ? result : n * n;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{1, 1}, {1, 0}};

  cout << sol.largestIsland(grid);

  return 0;
}