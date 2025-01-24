#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countConsistentStringsBetter(string allowed, vector<string> &words)
  {
    vector<int> freqArray(26, 0);

    for (char ch : allowed)
      freqArray[ch - 'a']++;

    int result = 0;

    for (string word : words)
    {
      bool flag = true;

      for (char ch : word)
      {
        if (freqArray[ch - 'a'] == 0)
        {
          flag = false;
          break;
        }
      }

      if (flag)
        result++;
    }

    return result;
  }

  int countConsistentStringsOptimal(string allowed, vector<string> &words)
  {
    int mask = 0;

    for (char ch : allowed)
      mask |= 1 << (ch - 'a');

    int result = 0;

    for (string word : words)
    {
      bool flag = true;

      for (char ch : word)
      {
        if (!((mask >> (ch - 'a')) & 1))
        {
          flag = false;
          break;
        }
      }

      if (flag)
        result++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string allowed = "ab";
  vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};

  cout << sol.countConsistentStringsBetter(allowed, words) << endl;
  cout << sol.countConsistentStringsOptimal(allowed, words) << endl;

  return 0;
}