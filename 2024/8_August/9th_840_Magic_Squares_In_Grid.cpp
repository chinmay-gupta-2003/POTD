#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkRows(vector<vector<int>> &grid, int row, int col)
  {
    vector<int> nums(9, 0);

    for (int i = row; i < row + 3; i++)
    {
      int sum = 0;

      for (int j = col; j < col + 3; j++)
      {
        if (grid[i][j] > 9 || grid[i][j] < 1 || sum > 15)
          return false;

        if (nums[grid[i][j] - 1])
          return false;

        nums[grid[i][j] - 1]++;

        sum += grid[i][j];
      }

      if (sum != 15)
        return false;
    }

    return true;
  }

  bool checkCols(vector<vector<int>> &grid, int row, int col)
  {
    for (int j = col; j < col + 3; j++)
    {
      int sum = 0;

      for (int i = row; i < row + 3; i++)
      {
        if (grid[i][j] > 9 || grid[i][j] < 1 || sum > 15)
          return false;

        sum += grid[i][j];
      }

      if (sum != 15)
        return false;
    }

    return true;
  }

  bool checkDiagonals(vector<vector<int>> &grid, int row, int col)
  {
    int leftSum = 0;
    int rightSum = 0;

    for (int i = 0; i < 3; i++)
    {
      if (grid[i + row][i + col] > 9 || grid[i + row][i + col] < 1)
        return false;

      leftSum += grid[i + row][i + col];

      if (grid[i + row][col + 2 - i] > 9 || grid[i + row][col + 2 - i] < 1)
        return false;

      rightSum += grid[i + row][col + 2 - i];
    }

    return leftSum == 15 && rightSum == 15;
  }

  int numMagicSquaresInsideBrute(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    int cnt = 0;

    if (m < 3 || n < 3)
      return 0;

    for (int i = 0; i < m - 2; i++)
    {
      for (int j = 0; j < n - 2; j++)
      {
        if (checkRows(grid, i, j) && checkCols(grid, i, j) && checkDiagonals(grid, i, j))
          cnt += 1;
      }
    }

    return cnt;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};

  cout << sol.numMagicSquaresInsideBrute(grid) << endl;

  return 0;
}