#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSquaresBrute(vector<vector<int>> &matrix)
  {
    int rows = matrix.size(), cols = matrix[0].size();

    int range = min(rows, cols), cnt = 0;

    for (int k = 1; k <= range; k++)
    {
      for (int i = 0; i <= rows - k; i++)
      {
        for (int j = 0; j <= cols - k; j++)
        {
          bool flag = true;

          for (int m = i; m < i + k; m++)
          {
            for (int n = j; n < j + k; n++)
            {
              if (matrix[m][n] != 1)
              {
                flag = false;
                break;
              }
            }

            if (!flag)
              break;
          }

          if (flag)
            cnt++;
        }
      }
    }

    return cnt;
  }

  int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
  {
    if (i >= matrix.size() || j >= matrix[0].size() || matrix[i][j] == 0)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int right = solve(i, j + 1, matrix, dp);
    int diagonal = solve(i + 1, j + 1, matrix, dp);
    int bottom = solve(i + 1, j, matrix, dp);

    return dp[i][j] = 1 + min(min(right, diagonal), bottom);
  }

  int countSquaresMemoization(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    int result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (matrix[i][j])
          result += solve(i, j, matrix, dp);
      }
    }

    return result;
  }

  int countSquaresBottomUp(vector<vector<int>> &matrix)
  {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int result = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = m - 1; j >= 0; j--)
      {
        if (!matrix[i][j])
          continue;

        int right = 0, diagonal = 0, bottom = 0;

        if (j + 1 < m)
          right = dp[i][j + 1];

        if (i + 1 < n && j + 1 < m)
          diagonal = dp[i + 1][j + 1];

        if (i + 1 < n)
          bottom = dp[i + 1][j];

        dp[i][j] = 1 + min(min(right, diagonal), bottom);

        result += dp[i][j];
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};

  cout << sol.countSquaresBrute(matrix) << endl;
  cout << sol.countSquaresMemoization(matrix) << endl;
  cout << sol.countSquaresBottomUp(matrix) << endl;

  return 0;
}