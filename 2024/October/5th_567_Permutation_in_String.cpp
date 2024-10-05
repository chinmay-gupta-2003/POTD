#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkInclusionBrute(string s1, string s2)
  {
    int l1 = s1.length(), l2 = s2.length();

    if (l1 > l2)
      return false;

    sort(s1.begin(), s1.end());

    for (int i = 0; i <= l2 - l1; i++)
    {
      string subStr = s2.substr(i, l1);

      sort(subStr.begin(), subStr.end());

      if (s1 == subStr)
        return true;
    }

    return false;
  }

  bool checkInclusionOptimal(string s1, string s2)
  {
    int l1 = s1.length(), l2 = s2.length();

    if (l1 > l2)
      return false;

    int l = 0, r = 0;
    vector<int> freqMap(26, 0), windowFreqMap(26, 0);

    for (auto it : s1)
      freqMap[it - 'a']++;

    while (r < l2)
    {
      windowFreqMap[s2[r] - 'a']++;

      if (r - l + 1 > l1)
        windowFreqMap[s2[l++] - 'a']--;

      if (r - l + 1 == l1 && freqMap == windowFreqMap)
        return true;

      r++;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  string s1 = "adc", s2 = "dcda";

  cout << sol.checkInclusionBrute(s1, s2) << endl;
  cout << sol.checkInclusionOptimal(s1, s2) << endl;

  return 0;
}