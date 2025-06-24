#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxAdjacentDistance(vector<int> &nums)
  {
    int n = nums.size(), maxDiff = 0;

    for (int i = 0; i < n - 1; i++)
      maxDiff = max(maxDiff, abs(nums[i + 1] - nums[i]));

    maxDiff = max(maxDiff, abs(nums[n - 1] - nums[0]));

    return maxDiff;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {1, 2, 4};

  cout << sol.maxAdjacentDistance(nums);

  return 0;
}