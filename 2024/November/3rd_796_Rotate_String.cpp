#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool rotateStringBrute(string s, string goal)
  {
    if (goal == s)
      return true;

    for (int i = 1; i <= s.length() - 1; i++)
    {
      rotate(s.begin(), s.begin() + 1, s.end());

      if (s == goal)
        return true;
    }

    return false;
  }

  bool rotateString(string s, string goal)
  {
    if (s.length() != goal.length())
      return false;

    s += s;

    for (int i = 0; i < goal.length(); i++)
    {
      if (s.substr(i, goal.length()) == goal)
        return true;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  string s = "aa", goal = "a";

  cout << sol.rotateStringBrute(s, goal) << endl;
  cout << sol.rotateString(s, goal) << endl;

  return 0;
}