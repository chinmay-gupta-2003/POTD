#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int i, string &s, vector<string> &dictionary, unordered_set<string> &dictSet, vector<int> &dp)
  {
    if (i >= s.length())
      return 0;

    if (dp[i] != -1)
      return dp[i];

    int skip = 1 + solve(i + 1, s, dictionary, dictSet, dp);

    for (int j = i; j < s.length(); j++)
    {
      if (dictSet.find(s.substr(i, j - i + 1)) != dictSet.end())
        skip = min(skip, solve(j + 1, s, dictionary, dictSet, dp));
    }

    return dp[i] = skip;
  }

  int minExtraCharMemoization(string s, vector<string> &dictionary)
  {
    int n = s.length();

    unordered_set<string> dictSet(dictionary.begin(), dictionary.end());

    vector<int> dp(n, -1);

    return solve(0, s, dictionary, dictSet, dp);
  }

  int minExtraCharTabulation(string s, vector<string> &dictionary)
  {
    int n = s.length();

    unordered_set<string> dictSet(dictionary.begin(), dictionary.end());

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
      int skip = 1 + dp[i + 1];

      for (int j = i; j < n; j++)
      {
        if (dictSet.find(s.substr(i, j - i + 1)) != dictSet.end())
          skip = min(skip, dp[j + 1]);
      }

      dp[i] = skip;
    }

    return dp[0];
  }
};

int main()
{
  Solution sol;
  string s = "sayhelloworld";
  vector<string> dictionary = {"hello", "world"};

  cout << sol.minExtraCharMemoization(s, dictionary) << endl;
  cout << sol.minExtraCharTabulation(s, dictionary) << endl;

  return 0;
}