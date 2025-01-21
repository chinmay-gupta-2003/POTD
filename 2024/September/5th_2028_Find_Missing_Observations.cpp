#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n)
  {
    int m = rolls.size();

    int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
    int sum_n = mean * (n + m) - sum_m;

    if (sum_n > n * 6 || sum_n < n)
      return {};

    int initVal_n = sum_n / n;
    int remainingVal_n = sum_n % n;

    vector<int> result(n, initVal_n);

    for (int i = 0; i < remainingVal_n; i++)
      result[i]++;

    return result;
  }
};

int main()
{
  Solution sol;

  vector<int> rolls = {1, 5, 6};
  int mean = 3, n = 4;

  auto ans = sol.missingRolls(rolls, mean, n);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}