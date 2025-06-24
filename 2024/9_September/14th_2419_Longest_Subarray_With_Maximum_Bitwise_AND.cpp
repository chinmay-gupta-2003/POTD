#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSubarrayBrute(vector<int> &nums)
  {
    int n = nums.size(), maxElement = 0;

    for (int i = 0; i < n; i++)
      maxElement = max(maxElement, nums[i]);

    int result = 0;

    for (int i = 0; i < n; i++)
    {
      int size = 0;

      while (i < n && nums[i] == maxElement)
      {
        i++;
        size++;
      }

      result = max(result, size);
    }

    return result;
  }

  int longestSubarrayOptimal(vector<int> &nums)
  {
    int maxElement = 0, consecutiveSequence = 0, result = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == maxElement)
        consecutiveSequence++;

      else if (nums[i] > maxElement)
      {
        maxElement = nums[i];
        consecutiveSequence = 1;
        result = 1;
      }

      else
        consecutiveSequence = 0;

      result = max(result, consecutiveSequence);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 4, 4, 4, 4, 4, 3, 3, 3, 3};

  cout << sol.longestSubarrayBrute(nums) << endl;
  cout << sol.longestSubarrayOptimal(nums) << endl;

  return 0;
}