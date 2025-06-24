#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(long long num, int &k, int limit, int &result)
  {
    if (result > -1)
      return;

    k--;

    if (k == 0)
    {
      result = num;
      return;
    }

    for (int i = 0; i <= 9; i++)
    {
      long long number = num * 10 + i;

      if (number <= limit)
        dfs(number, k, limit, result);
    }
  }

  int findKthNumberBrute(int n, int k)
  {
    int result = -1;

    for (int i = 1; i <= 9; i++)
    {
      if (result != -1)
        return result;

      dfs(i, k, n, result);
    }

    return result;
  }

  int countNumbers(int curr, int next, int limit)
  {
    int count = 0;

    while (curr <= limit)
    {
      count += next - curr;

      curr *= 10;
      next *= 10;

      next = min(next, limit + 1);
    }

    return count;
  }

  int findKthNumberOptimal(int n, int k)
  {
    int result = 1;
    k--;

    while (k > 0)
    {
      int count = countNumbers(result, result + 1, n);

      if (count <= k)
      {
        k -= count;
        result++;
      }
      else
      {
        result *= 10;
        k--;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int n = 13, k = 2;

  cout << sol.findKthNumberBrute(n, k) << endl;
  cout << sol.findKthNumberOptimal(n, k) << endl;

  return 0;
}