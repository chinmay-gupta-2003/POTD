#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string addSpaces(string s, vector<int> &spaces)
  {
    string result = "";
    int prevIdx = 0;

    for (auto it : spaces)
    {
      result += s.substr(prevIdx, it - prevIdx) + " ";

      prevIdx = it;
    }

    if (prevIdx < s.length())
      result += s.substr(prevIdx);

    return result;
  }
};

int main()
{
  Solution sol;

  string s = "LeetcodeHelpsMeLearn";
  vector<int> spaces = {8, 13, 15};

  cout << sol.addSpaces(s, spaces);

  return 0;
}