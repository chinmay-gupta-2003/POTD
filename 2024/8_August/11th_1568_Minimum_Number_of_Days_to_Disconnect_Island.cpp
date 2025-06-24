#include <bits/stdc++.h>
using namespace std;

class Solution
{
  void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int i, int j)
  {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || !grid[i][j] || vis[i][j])
      return;

    vis[i][j] = 1;

    dfs(grid, vis, i + 1, j);
    dfs(grid, vis, i - 1, j);
    dfs(grid, vis, i, j + 1);
    dfs(grid, vis, i, j - 1);
  }

  int countIslands(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));

    int numIslands = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!vis[i][j] && grid[i][j])
        {
          numIslands++;
          dfs(grid, vis, i, j);
        }
      }
    }

    return numIslands;
  }

public:
  int minDaysBrute(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    int islands = countIslands(grid);

    if (islands != 1)
      return 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j])
        {
          grid[i][j] = 0;

          int newIslands = countIslands(grid);

          if (newIslands != 1)
            return 1;

          grid[i][j] = 1;
        }
      }
    }

    return 2;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 1}, {1, 1, 0}};

  cout << sol.minDaysBrute(grid);

  return 0;
}