#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void solve(int i, string &s, int currCount, int &maxCount, unordered_set<string> &us)
  {
    if (currCount + s.length() - i <= maxCount)
      return;

    if (i >= s.length())
    {
      maxCount = max(maxCount, currCount);

      return;
    }

    for (int j = i; j < s.length(); j++)
    {
      string subString = s.substr(i, j - i + 1);

      if (us.find(subString) == us.end())
      {
        us.insert(subString);
        solve(j + 1, s, currCount + 1, maxCount, us);
        us.erase(subString);
      }
    }
  }

  int maxUniqueSplit(string s)
  {
    int n = s.length();
    int currCount = 0, maxCount = 0;

    unordered_set<string> us;

    solve(0, s, currCount, maxCount, us);

    return maxCount;
  }
};

int main()
{
  Solution sol;
  string s = "ababccc";

  cout << sol.maxUniqueSplit(s) << endl;

  return 0;
}