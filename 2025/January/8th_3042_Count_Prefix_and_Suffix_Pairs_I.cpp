#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countPrefixSuffixPairs(vector<string> &words)
  {
    int n = words.size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {
      int l1 = words[i].length();

      for (int j = i + 1; j < n; j++)
      {
        int l2 = words[j].length();

        if (l1 > l2)
          continue;

        if (words[j].substr(0, l1) == words[i] && words[j].substr(l2 - l1, l1) == words[i])
          count++;
      }
    }

    return count;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"pa", "papa", "ma", "mama"};

  cout << sol.countPrefixSuffixPairs(words) << endl;

  return 0;
}