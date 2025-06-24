#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumDifference(vector<int> &nums)
  {
    int n = nums.size(), maxi = nums[n - 1], result = INT_MIN;

    for (int i = n - 2; i >= 0; i--)
    {
      if (nums[i] >= maxi)
        maxi = nums[i];
      else
        result = max(result, maxi - nums[i]);
    }

    if (result == INT_MIN)
      return -1;

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {7, 1, 5, 4};

  cout << sol.maximumDifference(nums);

  return 0;
}