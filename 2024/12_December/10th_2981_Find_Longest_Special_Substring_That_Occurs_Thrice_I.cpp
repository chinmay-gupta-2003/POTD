#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumLengthBrute(string s)
  {
    int n = s.length();
    unordered_map<string, int> freqMap;

    for (int i = 0; i < n; i++)
    {
      string str = "";

      for (int j = i; j < n; j++)
      {
        str += s[j];

        if (j > i && str[j - i] != str[j - i - 1])
          break;

        freqMap[str]++;
      }
    }

    int maxLen = -1;

    for (auto it : freqMap)
    {
      if (it.second > 2)
        maxLen = max(maxLen, (int)it.first.length());
    }

    return maxLen;
  }

  int maximumLengthBetter(string s)
  {
    int n = s.length();
    map<pair<char, int>, int> freqMap;

    for (int i = 0; i < n; i++)
    {
      char currChar = s[i];
      int len = 1;

      for (int j = i; j < n; j++)
      {
        if (s[j] == currChar)
        {
          freqMap[{currChar, len}]++;
          len++;
        }
        else
          break;
      }
    }

    int maxLen = -1;

    for (auto it : freqMap)
    {
      if (it.second > 2)
        maxLen = max(maxLen, it.first.second);
    }

    return maxLen;
  }

  int maximumLengthOptimal(string s)
  {
    int n = s.length();
    vector<vector<int>> freqMatrix(26, vector<int>(n + 1, 0));

    char currChar = s[0];
    int len = 0;

    for (int i = 0; i < n; i++)
    {
      if (s[i] == currChar)
        len++;
      else
      {
        currChar = s[i];
        len = 1;
      }

      freqMatrix[s[i] - 'a'][len]++;
    }

    int maxLen = -1;

    for (int row = 0; row < 26; row++)
    {
      for (int col = n; col >= 1; col--)
      {
        if (freqMatrix[row][col] > 2)
          maxLen = max(maxLen, col);

        freqMatrix[row][col - 1] += freqMatrix[row][col];
      }
    }

    return maxLen;
  }
};

int main()
{
  Solution sol;

  string s = "aabcaabaa";

  cout << sol.maximumLengthBrute(s) << endl;
  cout << sol.maximumLengthBetter(s) << endl;
  cout << sol.maximumLengthOptimal(s) << endl;

  return 0;
}