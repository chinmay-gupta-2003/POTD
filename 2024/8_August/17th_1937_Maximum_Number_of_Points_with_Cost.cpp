#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int solve(vector<vector<int>> &points, int row, int col, int m, int n)
  {
    if (row >= m || col >= n || row < 0 || col < 0)
      return 0;

    if (row == m - 1)
      return points[row][col];

    int maxi = INT_MIN;
    for (int j = 0; j < n; j++)
    {
      int pts = points[row][col] - abs(col - j) + solve(points, row + 1, j, m, n);

      maxi = max(maxi, pts);
    }

    return maxi;
  }

  int solveMemoization(vector<vector<int>> &points, int row, int col, int m, int n, vector<vector<int>> &dp)
  {
    if (row >= m || col >= n || row < 0 || col < 0)
      return 0;

    if (row == m - 1)
      return points[row][col];

    if (dp[row][col] != -1)
      return dp[row][col];

    int maxi = INT_MIN;
    for (int j = 0; j < n; j++)
    {
      int pts = points[row][col] - abs(col - j) + solveMemoization(points, row + 1, j, m, n, dp);

      maxi = max(maxi, pts);
    }

    return dp[row][col] = maxi;
  }

public:
  long long maxPointsBrute(vector<vector<int>> &points)
  {
    int m = points.size(), n = points[0].size();

    int result = INT_MIN;

    for (int j = 0; j < n; j++)
      result = max(result, solve(points, 0, j, m, n));

    return result;
  }

  long long maxPointsMemoization(vector<vector<int>> &points)
  {
    int m = points.size(), n = points[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int result = INT_MIN;

    for (int j = 0; j < n; j++)
      result = max(result, solveMemoization(points, 0, j, m, n, dp));

    return result;
  }

  long long maxPointsTabulation(vector<vector<int>> &points)
  {
    int m = points.size(), n = points[0].size();

    vector<vector<long long>> dp(m, vector<long long>(n, 0));

    for (int row = m - 1; row >= 0; row--)
    {
      for (int col = 0; col < n; col++)
      {
        if (row == m - 1)
        {
          dp[row][col] = points[row][col];
          continue;
        }

        long long maxi = INT_MIN;
        for (int j = 0; j < n; j++)
        {
          long long pts = points[row][col] - abs(col - j) + dp[row + 1][j];

          maxi = max(maxi, pts);
        }

        dp[row][col] = maxi;
      }
    }

    long long result = LONG_LONG_MIN;

    for (int j = 0; j < n; j++)
      result = max(result, dp[0][j]);

    return result;
  }

  long long maxPointsSpaceOptimized(vector<vector<int>> &points)
  {
    int m = points.size(), n = points[0].size();

    vector<long long> next(n, 0), curr(n, 0);

    for (int row = m - 1; row >= 0; row--)
    {
      for (int col = 0; col < n; col++)
      {
        if (row == m - 1)
        {
          curr[col] = points[row][col];
          continue;
        }

        long long maxi = INT_MIN;
        for (int j = 0; j < n; j++)
        {
          long long pts = points[row][col] - abs(col - j) + next[j];

          maxi = max(maxi, pts);
        }

        curr[col] = maxi;
      }

      next = curr;
    }

    long long result = LONG_LONG_MIN;

    for (int j = 0; j < n; j++)
      result = max(result, curr[j]);

    return result;
  }

  long long maxPointsOptimal(vector<vector<int>> &points)
  {
    int m = points.size(), n = points[0].size();

    vector<long long> prev(n, 0);

    for (int col = 0; col < n; col++)
      prev[col] = points[0][col];

    for (int row = 1; row < m; row++)
    {
      vector<long long> left(n, 0);
      left[0] = prev[0];

      for (int col = 1; col < n; col++)
        left[col] = max(prev[col], left[col - 1] - 1);

      vector<long long> right(n, 0);
      right[n - 1] = prev[n - 1];

      for (int col = n - 2; col >= 0; col--)
        right[col] = max(prev[col], right[col + 1] - 1);

      for (int col = 0; col < n; col++)
        prev[col] = points[row][col] + max(left[col], right[col]);
    }

    long long result = LONG_LONG_MIN;

    for (int j = 0; j < n; j++)
      result = max(result, prev[j]);

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> points = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};

  cout << sol.maxPointsBrute(points) << endl;
  cout << sol.maxPointsMemoization(points) << endl;
  cout << sol.maxPointsTabulation(points) << endl;
  cout << sol.maxPointsSpaceOptimized(points) << endl;
  cout << sol.maxPointsOptimal(points) << endl;

  return 0;
}