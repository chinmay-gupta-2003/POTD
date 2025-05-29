#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long getLogCost(int l, int k)
  {
    long long cost = LONG_LONG_MAX;

    if (l <= k)
      return 0;

    for (long long len1 = 0; len1 <= k; len1++)
    {
      long long len2 = l - len1;

      if (len2 <= k)
        cost = min(cost, len1 * len2);
    }

    return cost;
  }

  long long minCuttingCostBrute(int n, int m, int k)
  {
    return getLogCost(n, k) + getLogCost(m, k);
  }

  long long minCuttingCostOptimal(int n, int m, int k)
  {
    if (n < m)
      swap(n, m);

    if (n <= k)
      return 0;

    return 1LL * k * (n - k);
  }
};

int main()
{
  Solution sol;
  int n = 49898, m = 109372, k = 62703;

  cout << sol.minCuttingCostBrute(n, m, k) << endl;
  cout << sol.minCuttingCostOptimal(n, m, k) << endl;

  return 0;
}