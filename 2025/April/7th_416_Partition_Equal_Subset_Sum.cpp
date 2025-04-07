#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool solve(vector<int> &nums, int index, int sum, vector<vector<int>> &dp)
  {
    if (sum == 0)
      return true;

    if (index >= nums.size())
      return false;

    if (dp[index][sum] != -1)
      return dp[index][sum];

    int notPick = solve(nums, index + 1, sum, dp);

    int pick = false;
    if (nums[index] <= sum)
      pick = solve(nums, index + 1, sum - nums[index], dp);

    return dp[index][sum] = pick || notPick;
  }

  bool canPartition(vector<int> &nums)
  {
    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    if (sum % 2)
      return false;

    return solve(nums, 0, sum / 2, dp);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};

  cout << sol.canPartition(nums);

  return 0;
}