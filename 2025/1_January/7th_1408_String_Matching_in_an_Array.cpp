#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> stringMatchingSTL(vector<string> &words)
  {
    int n = words.size();
    vector<string> result;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;

        if (words[j].find(words[i]) != string::npos)
        {
          result.push_back(words[i]);
          break;
        }
      }
    }

    return result;
  }

  void computeLPS(string &pattern, vector<int> &lps)
  {
    int m = pattern.length();
    int i = 1, currentLPS = 0;

    lps[0] = 0;

    while (i < m)
    {
      if (pattern[i] == pattern[currentLPS])
      {
        lps[i] = ++currentLPS;

        i++;
      }

      else
      {
        if (currentLPS != 0)
          currentLPS = lps[currentLPS - 1];
        else
        {
          lps[i] = 0;
          i++;
        }
      }
    }
  }

  bool KMP(string &pattern, string &word)
  {
    vector<int> lps(pattern.length(), 0);
    computeLPS(pattern, lps);

    int k = 0, l = 0;

    while (k < word.length())
    {
      if (pattern[l] == word[k])
      {
        k++;
        l++;
      }
      else
      {
        if (l != 0)
          l = lps[l - 1];
        else
          k++;
      }

      if (l == pattern.length())
        return true;
    }

    return false;
  }

  vector<string> stringMatching(vector<string> &words)
  {
    int n = words.size();
    vector<string> result;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;

        if (KMP(words[i], words[j]))
        {
          result.push_back(words[i]);
          break;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"leetcode", "et", "code"};

  auto ans = sol.stringMatching(words);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}