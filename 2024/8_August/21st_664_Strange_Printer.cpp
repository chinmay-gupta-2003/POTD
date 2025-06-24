#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int l, int r, string &s, vector<vector<int>> &dp)
  {
    if (l == r)
      return 1;

    if (l > r)
      return 0;

    if (dp[l][r] != -1)
      return dp[l][r];

    int i = l + 1;
    while (i <= r && s[i] == s[l])
      i++;

    int basic = 1 + solve(i, r, s, dp);

    int greedy = INT_MAX;

    for (int j = i; j <= r; j++)
    {
      if (s[j] == s[l])
      {
        int val = solve(i, j - 1, s, dp) + solve(j, r, s, dp);

        greedy = min(greedy, val);
      }
    }

    return dp[l][r] = min(basic, greedy);
  }

  int strangePrinter(string s)
  {
    int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return solve(0, n - 1, s, dp);
  }
};

int main()
{
  Solution sol;
  string s = "aaabaaaac";

  cout << sol.strangePrinter(s) << endl;

  return 0;
}