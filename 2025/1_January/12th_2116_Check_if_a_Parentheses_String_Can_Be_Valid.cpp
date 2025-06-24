#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canBeValidBetter(string &s, string &l)
  {
    stack<int> open, openClose;

    if (s.length() % 2)
      return false;

    for (int i = 0; i < s.length(); i++)
    {
      if (l[i] == '1')
      {
        if (s[i] == '(')
          open.push(i);
        else
        {
          if (open.empty() && openClose.empty())
            return false;

          if (!open.empty())
            open.pop();
          else
            openClose.pop();
        }
      }
      else
        openClose.push(i);
    }

    while (!open.empty() && !openClose.empty() && open.top() < openClose.top())
    {
      open.pop();
      openClose.pop();
    }

    return open.empty();
  }

  bool canBeValidOptimal(string &s, string &l)
  {
    int n = s.length();
    int open = 0, close = 0;

    for (int i = 0; i < n; i++)
    {
      if (l[i] == '0' || s[i] == '(')
        open++;
      else
        open--;

      if (l[n - 1 - i] == '0' || s[n - 1 - i] == ')')
        close++;
      else
        close--;

      if (open < 0 || close < 0)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  string s = "))())(", locked = "010101";

  cout << sol.canBeValidBetter(s, locked) << endl;
  cout << sol.canBeValidOptimal(s, locked) << endl;

  return 0;
}