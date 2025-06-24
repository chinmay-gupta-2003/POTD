#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string makeFancyString(string s)
  {
    string fancyString = "";
    fancyString += s[0];

    int cnt = 1;

    for (int i = 1; i < s.length(); i++)
    {
      if (s[i] == s[i - 1])
        cnt++;
      else
        cnt = 1;

      if (cnt > 2)
        continue;

      fancyString += s[i];
    }

    return fancyString;
  }
};

int main()
{
  Solution sol;
  string s = "lllleeetcooddde";

  cout << sol.makeFancyString(s) << endl;

  return 0;
}