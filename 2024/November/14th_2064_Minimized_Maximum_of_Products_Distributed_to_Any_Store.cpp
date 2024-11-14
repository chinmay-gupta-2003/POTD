#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPossible(int mid, vector<int> &quantities, int n)
  {
    int storesRequired = 0;

    if (mid == 0)
      return false;

    for (int i = 0; i < quantities.size(); i++)
    {
      storesRequired += ceil(quantities[i] / (double)mid);

      if (storesRequired > n)
        return false;
    }

    return true;
  }

  int minimizedMaximum(int n, vector<int> &quantities)
  {
    int low = 0, high = *max_element(quantities.begin(), quantities.end()), x;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (isPossible(mid, quantities, n))
      {
        x = mid;
        high = mid - 1;
      }
      else
        low = mid + 1;
    }

    return x;
  }
};

int main()
{
  Solution sol;

  int n = 6;
  vector<int> quantities = {11, 6};

  cout << sol.minimizedMaximum(n, quantities);

  return 0;
}