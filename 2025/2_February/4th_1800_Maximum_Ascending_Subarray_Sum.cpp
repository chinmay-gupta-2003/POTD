#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxAscendingSum(vector<int> &nums)
  {
    int n = nums.size();
    int maxSum = nums[0], currSum = nums[0];

    for (int i = 1; i < n; i++)
    {
      if (nums[i] > nums[i - 1])
        currSum += nums[i];
      else
        currSum = nums[i];

      maxSum = max(maxSum, currSum);
    }

    return maxSum;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {10, 20, 30, 5, 10, 50};

  cout << sol.maxAscendingSum(nums);

  return 0;
}