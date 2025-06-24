#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(long long num, int limit, int &k, int &ans)
  {
    if (ans > 0)
      return;

    k--;

    if (k == 0)
    {
      ans = num;

      return;
    }

    for (int i = 0; i <= 9; i++)
    {
      long long nextNum = num * 10 + i;

      if (nextNum <= limit)
        dfs(nextNum, limit, k, ans);
    }
  }

  int findKthNumberBrute(int n, int k)
  {
    int ans = -1;

    for (int i = 1; i <= 9; i++)
    {
      dfs(i, n, k, ans);

      if (ans > 0)
        break;
    }

    return ans;
  }

  int countNums(int curr, int next, int limit)
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
    int curr = 1;
    k--;

    while (k > 0)
    {
      int count = countNums(curr, curr + 1, n);

      if (count <= k)
      {
        k -= count;
        curr++;
      }
      else
      {
        curr *= 10;
        k--;
      }
    }

    return curr;
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