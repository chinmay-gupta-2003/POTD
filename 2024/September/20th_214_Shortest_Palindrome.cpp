#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string shortestPalindromeBrute(string s)
  {
    int n = s.length();

    string rev = s;
    reverse(rev.begin(), rev.end());

    if (rev == s)
      return s;

    int i = 1;

    while (i < n)
    {
      if (s.substr(0, n - i) == rev.substr(i))
        break;

      i++;
    }

    return rev.substr(0, i) + s;
  }

  string shortestPalindromeBetter(string s)
  {
    int n = s.length();

    string rev = s;
    reverse(rev.begin(), rev.end());

    if (rev == s)
      return s;

    int i = 1;

    while (i < n)
    {
      if (memcmp(s.c_str(), rev.c_str() + i, n - i) == 0)
        break;

      i++;
    }

    return rev.substr(0, i) + s;
  }

  void computeLps(string s, vector<int> &lps)
  {
    lps[0] = 0;

    int i = 1, length = 0;

    while (i < s.length())
    {
      if (s[i] == s[length])
      {
        lps[i] = ++length;

        i++;
      }
      else
      {
        if (length == 0)
        {
          lps[i] = 0;
          i++;
        }
        else
          length = lps[length - 1];
      }
    }
  }

  string shortestPalindromeOptimal(string s)
  {
    int n = s.length();

    string rev = s;
    reverse(rev.begin(), rev.end());

    if (rev == s)
      return s;

    vector<int> lps(2 * n + 1, 0);

    computeLps(s + "@" + rev, lps);

    int index = lps[2 * n];

    return rev.substr(0, n - index) + s;
  }
};

int main()
{
  Solution sol;
  string s = "aacecaaa";

  cout << sol.shortestPalindromeBrute(s) << endl;
  cout << sol.shortestPalindromeBetter(s) << endl;
  cout << sol.shortestPalindromeOptimal(s) << endl;

  return 0;
}