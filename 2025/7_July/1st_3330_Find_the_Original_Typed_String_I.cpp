#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int possibleStringCount(string word)
  {
    int n = word.size(), result = 1;

    for (int i = 1; i < n; i++)
    {
      if (word[i] == word[i - 1])
        result++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string word = "abbcccc";

  cout << sol.possibleStringCount(word) << endl;

  return 0;
}