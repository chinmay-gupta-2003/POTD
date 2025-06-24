#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSubsets(int index, int currBitwiseOR, vector<int> nums, int maxBitwiseOr, vector<vector<int>> &dp)
  {
    if (index < 0)
      return currBitwiseOR == maxBitwiseOr ? 1 : 0;

    if (dp[index][currBitwiseOR] != -1)
      return dp[index][currBitwiseOR];

    int take = countSubsets(index - 1, nums[index] | currBitwiseOR, nums, maxBitwiseOr, dp);
    int notTake = countSubsets(index - 1, currBitwiseOR, nums, maxBitwiseOr, dp);

    return dp[index][currBitwiseOR] = take + notTake;
  }

  int countMaxOrSubsets(vector<int> &nums)
  {
    int n = nums.size();
    int maxBitwiseOr = 0;

    for (auto it : nums)
      maxBitwiseOr |= it;

    vector<vector<int>> dp(n, vector<int>(maxBitwiseOr + 1, -1));

    return countSubsets(n - 1, 0, nums, maxBitwiseOr, dp);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {3, 2, 1, 5};

  cout << sol.countMaxOrSubsets(nums) << endl;

  return 0;
}
