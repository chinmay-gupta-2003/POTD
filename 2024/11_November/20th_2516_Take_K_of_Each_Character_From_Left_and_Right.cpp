#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int takeCharacters(string s, int k)
  {
    int n = s.length();

    int cntA = 0, cntB = 0, cntC = 0;

    for (auto it : s)
    {
      if (it == 'a')
        cntA++;
      else if (it == 'b')
        cntB++;
      else
        cntC++;
    }

    if (cntA < k || cntB < k || cntC < k)
      return -1;

    int i = 0, j = 0, maxWindowSize = 0;

    while (j < n)
    {
      if (s[j] == 'a')
        cntA--;
      else if (s[j] == 'b')
        cntB--;
      else
        cntC--;

      while (i <= j && (cntA < k || cntB < k || cntC < k))
      {
        if (s[i] == 'a')
          cntA++;
        else if (s[i] == 'b')
          cntB++;
        else
          cntC++;

        i++;
      }

      maxWindowSize = max(maxWindowSize, j - i + 1);

      j++;
    }

    return n - maxWindowSize;
  }
};

int main()
{
  Solution sol;

  string s = "aabaaaacaabc";
  int k = 2;

  cout << sol.takeCharacters(s, k) << endl;

  return 0;
}