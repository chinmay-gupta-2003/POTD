#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> parent, size;

  DisjointSet(int n)
  {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++)
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

  void SetInitialSize(int node, int n)
  {
    size[node] = n;
  }
};

class Solution
{
public:
  void dfs(int i, int j, vector<vector<int>> &grid, int &fishes)
  {
    fishes += grid[i][j];
    grid[i][j] = 0;

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto coords : directions)
    {
      int n_i = i + coords[0];
      int n_j = j + coords[1];

      if (n_i >= 0 && n_i < grid.size() && n_j >= 0 && n_j < grid[0].size() && grid[n_i][n_j])
        dfs(n_i, n_j, grid, fishes);
    }
  }

  int findMaxFishDFS(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));

    int result = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
        {
          int fishes = 0;
          dfs(i, j, grid, fishes);

          result = max(result, fishes);
        }
      }
    }

    return result;
  }

  int findMaxFishDSU(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    DisjointSet DS(m * n);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
        DS.SetInitialSize(i * n + j, grid[i][j]);
    }

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
        {
          for (auto coords : directions)
          {
            int n_i = i + coords[0];
            int n_j = j + coords[1];

            if (n_i >= 0 && n_i < m && n_j >= 0 && n_j < n && grid[n_i][n_j])
              DS.UnionBySize(i * n + j, n_i * n + n_j);
          }
        }
      }
    }

    int result = 0;

    for (int i = 0; i < m * n; i++)
    {
      if (DS.parent[i] == i)
        result = max(result, DS.size[i]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}};

  cout << sol.findMaxFishDSU(grid) << endl;
  cout << sol.findMaxFishDFS(grid) << endl;

  return 0;
}