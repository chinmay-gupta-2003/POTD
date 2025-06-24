#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int MOD = 1e9 + 7;

  int lengthAfterTransformationsBrute(string s, int t)
  {
    while (t--)
    {
      int i = 0;

      while (i < s.length())
      {
        char ch = s[i];

        if (ch == 'z')
        {
          s[i] = 'a';
          s = s.substr(0, i + 1) + "b" + s.substr(i + 1);

          i++;
        }
        else
          s[i] = ++ch;

        i++;
      }
    }

    return s.length();
  }

  int lengthAfterTransformationsBetter(string s, int t)
  {
    unordered_map<char, int> freqMap;

    for (char ch : s)
      freqMap[ch]++;

    while (t--)
    {
      unordered_map<char, int> tempFreqMap;

      for (auto it : freqMap)
      {
        char ch = it.first;
        int freq = it.second;

        if (ch == 'z')
        {
          tempFreqMap['a'] = (tempFreqMap['a'] + freq) % MOD;
          tempFreqMap['b'] = (tempFreqMap['b'] + freq) % MOD;
        }
        else
          tempFreqMap[ch + 1] = (tempFreqMap[ch + 1] + freq) % MOD;
      }

      freqMap = tempFreqMap;
    }

    int result = 0;

    for (auto it : freqMap)
      result = (result + it.second) % MOD;

    return result;
  }

  int lengthAfterTransformationsOptimal(string s, int t)
  {
    vector<int> freqMap(26, 0);

    for (char ch : s)
      freqMap[ch - 'a']++;

    while (t--)
    {
      vector<int> tempFreqMap(26, 0);

      for (int i = 0; i < 26; i++)
      {
        char ch = i + 'a';
        int freq = freqMap[i];

        if (ch == 'z')
        {
          tempFreqMap['a' - 'a'] = (tempFreqMap['a' - 'a'] + freq) % MOD;
          tempFreqMap['b' - 'a'] = (tempFreqMap['b' - 'a'] + freq) % MOD;
        }
        else
          tempFreqMap[ch + 1 - 'a'] = (tempFreqMap[ch + 1 - 'a'] + freq) % MOD;
      }

      freqMap = tempFreqMap;
    }

    int result = 0;

    for (int it : freqMap)
      result = (result + it) % MOD;

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "abcyy";
  int t = 2;

  cout << sol.lengthAfterTransformationsBrute(s, t) << endl;
  cout << sol.lengthAfterTransformationsBetter(s, t) << endl;
  cout << sol.lengthAfterTransformationsOptimal(s, t) << endl;

  return 0;
}