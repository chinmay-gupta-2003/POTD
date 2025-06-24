#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string clearDigits(string s)
  {
    int n = s.size(), numCount = 0;

    string result = "";

    for (int i = n - 1; i >= 0; i--)
    {
      if (isdigit(s[i]))
      {
        numCount++;
        continue;
      }

      if (numCount == 0)
        result = s[i] + result;
      else
        numCount--;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "ab1b2c";

  cout << sol.clearDigits(s);

  return 0;
}