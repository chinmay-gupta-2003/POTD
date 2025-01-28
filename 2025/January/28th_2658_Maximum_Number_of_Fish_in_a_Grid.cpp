#include <bits/stdc++.h>
using namespace std;

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

  int findMaxFish(vector<vector<int>> &grid)
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
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}};

  cout << sol.findMaxFish(grid);

  return 0;
}