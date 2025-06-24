#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int num, vector<int> &result, int limit)
  {
    if (num > limit)
      return;

    result.push_back(num);

    for (int i = 0; i <= 9; i++)
    {
      int nextNum = num * 10 + i;

      dfs(nextNum, result, limit);
    }
  }

  vector<int> lexicalOrder(int n)
  {
    vector<int> result;

    for (int i = 1; i <= 9; i++)
    {
      dfs(i, result, n);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int n = 13;

  auto ans = sol.lexicalOrder(n);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}