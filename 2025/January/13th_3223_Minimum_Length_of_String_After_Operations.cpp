#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumLengthBrute(string s)
  {
    int n = s.length();
    vector<int> deleted(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (deleted[i])
        continue;

      int leftIndex = -1, rightIndex = -1;

      for (int l = 0; l < i; l++)
      {
        if (deleted[l])
          continue;

        if (s[l] == s[i])
        {
          leftIndex = l;
          break;
        }
      }

      if (leftIndex == -1)
        continue;

      for (int r = i + 1; r < n; r++)
      {
        if (deleted[r])
          continue;

        if (s[r] == s[i])
        {
          rightIndex = r;
          break;
        }
      }

      if (rightIndex != -1)
      {
        deleted[leftIndex] = 1;
        deleted[rightIndex] = 1;
      }
    }

    int result = 0;

    for (int it : deleted)
    {
      if (it == 0)
        result++;
    }

    return result;
  }

  int minimumLengthOptimal(string s)
  {
    int n = s.length();

    vector<int> freq(26, 0);

    for (int i = 0; i < n; i++)
      freq[s[i] - 'a']++;

    int result = 0;
    for (int i = 0; i < 26; i++)
    {
      if (freq[i] == 0)
        continue;

      if (freq[i] % 2)
        result++;
      else
        result += 2;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "abaacbcbb";

  cout << sol.minimumLengthBrute(s) << endl;
  cout << sol.minimumLengthOptimal(s) << endl;

  return 0;
}