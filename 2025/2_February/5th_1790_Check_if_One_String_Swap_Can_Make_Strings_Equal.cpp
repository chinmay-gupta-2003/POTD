#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool areAlmostEqualBrute(string s1, string s2)
  {
    vector<int> freq_one(26, 0), freq_two(26, 0);

    int diffCount = 0;

    for (int i = 0; i < s1.length(); i++)
    {
      freq_one[s1[i] - 'a']++;
      freq_two[s2[i] - 'a']++;

      if (s1[i] != s2[i])
        diffCount++;

      if (diffCount > 2)
        return false;
    }

    return freq_one == freq_two;
  }

  bool areAlmostEqualOptimal(string s1, string s2)
  {
    vector<int> diffIndex = {-1, -1};

    int diffCount = 0;

    for (int i = 0; i < s1.length(); i++)
    {
      if (s1[i] != s2[i])
      {
        if (diffCount == 2)
          return false;

        diffIndex[diffCount++] = i;
      }
    }

    if (diffCount == 0)
      return true;

    if (diffCount == 1)
      return false;

    return (s1[diffIndex[0]] == s2[diffIndex[1]] && s1[diffIndex[1]] == s2[diffIndex[0]]);
  }
};

int main()
{
  Solution sol;
  string s1 = "bank", s2 = "kanb";

  cout << sol.areAlmostEqualBrute(s1, s2) << endl;
  cout << sol.areAlmostEqualOptimal(s1, s2) << endl;

  return 0;
}