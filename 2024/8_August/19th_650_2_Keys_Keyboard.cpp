#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int currLen, int copyLen, int n)
  {
    if (currLen == n)
      return 0;

    if (currLen > n)
      return 1e4;

    int paste = 1e4;
    if (copyLen)
      paste = 1 + solve(currLen + copyLen, copyLen, n);

    int copyPaste = 2 + solve(2 * currLen, currLen, n);

    return min(paste, copyPaste);
  }

  int solveMemoization(int currLen, int copyLen, int n, vector<vector<int>> &dp)
  {
    if (currLen == n)
      return 0;

    if (currLen > n)
      return 1e4;

    if (dp[currLen][copyLen] != -1)
      return dp[currLen][copyLen];

    int paste = 1e4;
    if (copyLen)
      paste = 1 + solveMemoization(currLen + copyLen, copyLen, n, dp);

    int copyPaste = 2 + solveMemoization(2 * currLen, currLen, n, dp);

    return dp[currLen][copyLen] = min(paste, copyPaste);
  }

  int minStepsBrute(int n)
  {
    return solve(1, 0, n);
  }

  int minStepsMemoization(int n)
  {
    vector<vector<int>> dp(1001, vector<int>(1001, -1));

    return solveMemoization(1, 0, n, dp);
  }

  int minStepsOptimal(int n)
  {
    vector<int> steps(n + 1, 0);

    steps[0] = 0;
    steps[1] = 0;
    steps[2] = 2;

    for (int i = 3; i <= n; i++)
    {
      int factor = i / 2;

      while (factor > 0)
      {
        if (i % factor == 0)
        {
          steps[i] = steps[factor] + 1 + (i / factor - 1);

          break;
        }

        factor--;
      }
    }

    return steps[n];
  }
};

int main()
{
  Solution sol;
  int n = 10;

  cout << sol.minStepsBrute(n) << endl;
  cout << sol.minStepsMemoization(n) << endl;
  cout << sol.minStepsOptimal(n) << endl;

  return 0;
}