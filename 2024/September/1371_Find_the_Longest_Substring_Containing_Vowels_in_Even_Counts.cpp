#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isVowel(char ch)
  {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;

    return false;
  }

  bool isValid(unordered_map<char, int> &charFreq)
  {

    for (auto it : charFreq)
    {
      if (it.second % 2)
        return false;
    }

    return true;
  }

  int findTheLongestSubstringBrute(string s)
  {
    int n = s.length();
    int result = 0;

    for (int i = 0; i < n; i++)
    {
      unordered_map<char, int> charFreq;

      for (int j = i; j < n; j++)
      {
        if (isVowel(s[j]))
          charFreq[s[j]]++;

        if (isValid(charFreq))
          result = max(result, j - i + 1);
      }
    }

    return result;
  }

  int findTheLongestSubstringBetter(string s)
  {
    unordered_map<string, int> lastOccurance;

    string currentState = "00000";
    lastOccurance[currentState] = -1;

    int result = 0;
    vector<int> charFreq(5, 0);

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'a')
        charFreq[0] ^= 1;
      else if (s[i] == 'e')
        charFreq[1] ^= 1;
      else if (s[i] == 'i')
        charFreq[2] ^= 1;
      else if (s[i] == 'o')
        charFreq[3] ^= 1;
      else if (s[i] == 'u')
        charFreq[4] ^= 1;

      currentState = "";

      for (int freq : charFreq)
        currentState += to_string(freq);

      if (lastOccurance.find(currentState) != lastOccurance.end())
        result = max(result, i - lastOccurance[currentState]);
      else
        lastOccurance[currentState] = i;
    }

    return result;
  }

  int findTheLongestSubstringOptimal(string s)
  {
    unordered_map<int, int> lastOccurance;

    int result = 0;
    int currentState = 0;

    lastOccurance[currentState] = -1;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == 'a')
        currentState ^= (1 << 0);
      else if (s[i] == 'e')
        currentState ^= (1 << 1);
      else if (s[i] == 'i')
        currentState ^= (1 << 2);
      else if (s[i] == 'o')
        currentState ^= (1 << 3);
      else if (s[i] == 'u')
        currentState ^= (1 << 4);

      if (lastOccurance.find(currentState) != lastOccurance.end())
        result = max(result, i - lastOccurance[currentState]);
      else
        lastOccurance[currentState] = i;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "eleetminicoworoep";

  cout << sol.findTheLongestSubstringBrute(s) << endl;
  cout << sol.findTheLongestSubstringBetter(s) << endl;
  cout << sol.findTheLongestSubstringOptimal(s) << endl;

  return 0;
}