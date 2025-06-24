#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isParity(int num1, int num2)
  {
    return num1 % 2 != num2 % 2;
  }

  vector<bool> isArraySpecialBrute(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();
    vector<bool> result;

    for (auto it : queries)
    {
      int start = it[0], end = it[1];

      bool check = true;

      for (int i = start; i <= end; i++)
      {
        int prev = i - 1, next = i + 1;

        if (i != start && prev >= 0)
          check = check && isParity(nums[prev], nums[i]);

        if (i != end && next < n)
          check = check && isParity(nums[next], nums[i]);
      }

      result.push_back(check);
    }

    return result;
  }

  vector<bool> isArraySpecialOptimal1(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();

    vector<int> cumSum(n, 0);
    vector<bool> result;

    for (int i = 1; i < n; i++)
      cumSum[i] = isParity(nums[i - 1], nums[i]) ? cumSum[i - 1] : cumSum[i - 1] + 1;

    for (auto it : queries)
    {
      int start = it[0], end = it[1];

      if (cumSum[end] - cumSum[start] == 0)
        result.push_back(true);
      else
        result.push_back(false);
    }

    return result;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {4, 3, 1, 6};
  vector<vector<int>> queries = {{0, 2}, {2, 3}};

  auto ans = sol.isArraySpecialBrute(nums, queries);

  for (auto it : ans)
    cout << (it ? " true " : " false ");

  cout << endl;

  ans = sol.isArraySpecialOptimal1(nums, queries);

  for (auto it : ans)
    cout << (it ? " true " : " false ");

  return 0;
}