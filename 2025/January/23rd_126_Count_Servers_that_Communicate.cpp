#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canCommunicate(int i, int j, vector<vector<int>> &grid)
  {
    for (int row = 0; row < grid.size(); row++)
    {
      if (row == i)
        continue;

      if (grid[row][j])
        return true;
    }

    for (int col = 0; col < grid[0].size(); col++)
    {
      if (col == j)
        continue;

      if (grid[i][col])
        return true;
    }

    return false;
  }

  int countServersBrute(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> communicate(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] && canCommunicate(i, j, grid))
          communicate[i][j] = 1;
      }
    }

    int result = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (communicate[i][j])
          result++;
      }
    }

    return result;
  }

  int countServersOptimal(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    vector<int> rowsServer(m, 0), colsServer(n, 0);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!grid[i][j])
          continue;

        rowsServer[i]++;
        colsServer[j]++;
      }
    }

    int result = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] && (rowsServer[i] > 1 || colsServer[j] > 1))
          result++;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};

  cout << sol.countServersBrute(grid) << endl;
  cout << sol.countServersOptimal(grid) << endl;

  return 0;
}