#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solve(int idx, string &temp, string &s, int k)
  {
    if (idx == s.size())
      return 0;

    temp.push_back(s[idx]);

    int pick = 0;
    if (stoi(temp, nullptr, 2) <= k)
      pick = 1 + solve(idx + 1, temp, s, k);

    temp.pop_back();

    int notPick = solve(idx + 1, temp, s, k);

    return max(pick, notPick);
  }

  int longestSubsequenceBrute(string s, int k)
  {
    int n = s.length();
    string temp = "";

    return solve(0, temp, s, k);
  }

  int longestSubsequenceOptimal(string s, int k)
  {
    int n = s.length();
    long long power = 1;
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      if (s[n - 1 - i] == '0')
        result++;
      else if (k - power >= 0)
      {
        result++;

        k -= power;
      }

      if (power <= k)
        power *= 2;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "001010101011010100010101101010010";
  int k = 5;

  cout << sol.longestSubsequenceBrute(s, k) << endl;
  cout << sol.longestSubsequenceOptimal(s, k) << endl;

  return 0;
}