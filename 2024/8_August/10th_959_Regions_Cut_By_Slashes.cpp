#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(vector<vector<int>> &matrix, vector<vector<int>> &vis, int i, int j)
  {
    vis[i][j] = 1;

    vector<vector<int>> coords = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    for (auto it : coords)
    {
      int nrow = i + it[0];
      int ncol = j + it[1];

      if (nrow >= 0 && nrow < matrix.size() && ncol >= 0 && ncol < matrix[0].size() && matrix[i][j] == 0 && !vis[nrow][ncol])
        dfs(matrix, vis, nrow, ncol);
    }
  }

  int regionsBySlashes(vector<string> &grid)
  {
    int rows = grid.size(), cols = grid[0].size();

    vector<vector<int>> matrix(rows * 3, vector<int>(cols * 3, 0)), vis(rows * 3, vector<int>(cols * 3, 0));

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (grid[i][j] == '/')
        {
          matrix[i * 3][j * 3 + 2] = 1;
          matrix[i * 3 + 1][j * 3 + 1] = 1;
          matrix[i * 3 + 2][j * 3] = 1;
        }
        else if (grid[i][j] == '\\')
        {
          matrix[i * 3][j * 3] = 1;
          matrix[i * 3 + 1][j * 3 + 1] = 1;
          matrix[i * 3 + 2][j * 3 + 2] = 1;
        }
      }
    }

    int regions = 0;

    for (int i = 0; i < rows * 3; i++)
    {
      for (int j = 0; j < cols * 3; j++)
      {
        if (!vis[i][j] && matrix[i][j] == 0)
        {
          regions++;
          dfs(matrix, vis, i, j);
        }
      }
    }

    return regions;
  }
};

int main()
{
  Solution sol;
  vector<string> grid = {"/\\", "\\/"};

  cout << sol.regionsBySlashes(grid);

  return 0;
}