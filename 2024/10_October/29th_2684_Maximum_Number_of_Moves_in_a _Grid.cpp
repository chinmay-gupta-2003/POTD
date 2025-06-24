#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isValid(int row, int col, vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();

    if (row >= 0 && col >= 0 && row < n && col < m)
      return true;

    return false;
  }

  int solve(vector<vector<int>> &grid, int row, int col, int moves, vector<vector<int>> &dp)
  {
    int drow[] = {-1, 0, 1};
    int dcol[] = {1, 1, 1};

    if (dp[row][col] != -1)
      return dp[row][col];

    int maxi = moves;

    for (int i = 0; i < 3; i++)
    {
      int nrow = row + drow[i];
      int ncol = col + dcol[i];

      if (isValid(nrow, ncol, grid) && grid[nrow][ncol] > grid[row][col])
      {
        int move = solve(grid, nrow, ncol, moves + 1, dp);

        maxi = max(maxi, move);
      }
    }

    return dp[row][col] = maxi;
  }

  int maxMovesTopDown(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = 0;

    for (int i = 0; i < n; i++)
    {
      int moves = solve(grid, i, 0, 0, dp);

      maxi = max(maxi, moves);
    }

    return maxi;
  }

  int maxMovesBottomUp(vector<vector<int>> &grid)
  {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int drow[] = {-1, 0, 1};
    int dcol[] = {1, 1, 1};

    for (int row = n - 1; row >= 0; row--)
    {
      for (int col = m - 1; col >= 0; col--)
      {
        int maxi = 0;

        for (int i = 0; i < 3; i++)
        {
          int nrow = row + drow[i];
          int ncol = col + dcol[i];

          if (isValid(nrow, ncol, grid) && grid[nrow][ncol] > grid[row][col])
          {
            int move = dp[nrow][ncol] + 1;

            maxi = max(maxi, move);
          }
        }

        dp[row][col] = maxi;
      }
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
      int moves = dp[i][0];

      maxi = max(maxi, moves);
    }

    return maxi;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{2, 4, 3, 5},
                              {5, 4, 9, 3},
                              {3, 4, 2, 11},
                              {10, 9, 13, 15}};

  cout << sol.maxMovesTopDown(grid) << endl;

  return 0;
}