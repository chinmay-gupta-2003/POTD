#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long minEndBrute(int n, int x)
  {
    long long cnt = 1;
    long long bitWiseAnd = x, ele = x + 1;
    long long minNums = x;

    while (cnt < n)
    {
      if ((bitWiseAnd & ele) == x)
      {
        minNums = ele;
        cnt++;
      }

      ele++;
    }

    return minNums;
  }

  long long minEndOptimal(int n, int x)
  {
    long long prevNum = x;

    for (int i = 1; i < n; i++)
    {
      prevNum = (prevNum + 1) | x;
    }

    return prevNum;
  }
};

int main()
{
  Solution sol;
  int n = 3, x = 4;

  cout << sol.minEndBrute(n, x) << endl;
  cout << sol.minEndOptimal(n, x) << endl;

  return 0;
}