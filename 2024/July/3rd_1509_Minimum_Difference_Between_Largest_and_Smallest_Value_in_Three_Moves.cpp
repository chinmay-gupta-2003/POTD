#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minDifference(vector<int> &nums)
  {
    int n = nums.size();

    if (n <= 4)
      return 0;

    sort(nums.begin(), nums.end());

    int result = INT_MAX;

    for (int left = 0, right = n - 4; left < 4; left++, right++)
      result = min(result, nums[right] - nums[left]);

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 5, 0, 10, 14};

  cout << sol.minDifference(nums);

  return 0;
}