#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestMonotonicSubarray(vector<int> &nums)
  {
    int result = 1, increasingCount = 1, decreasingCount = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] > nums[i - 1])
      {
        increasingCount++;
        decreasingCount = 1;
      }
      else if (nums[i] < nums[i - 1])
      {
        increasingCount = 1;
        decreasingCount++;
      }
      else
      {
        increasingCount = 1;
        decreasingCount = 1;
      }

      result = max(result, max(increasingCount, decreasingCount));
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

  cout << sol.longestMonotonicSubarray(nums);

  return 0;
}