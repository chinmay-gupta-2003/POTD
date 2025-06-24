#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long continuousSubarraysBrute(vector<int> &nums)
  {
    int n = nums.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
      int maxVal = nums[i], minVal = nums[i];

      for (int j = i; j < n; j++)
      {
        maxVal = max(maxVal, nums[j]);
        minVal = min(minVal, nums[j]);

        if (maxVal - minVal <= 2)
          count++;
        else
          break;
      }
    }

    return count;
  }

  long long continuousSubarraysOptimal(vector<int> &nums)
  {
    int i = 0, j = 0, n = nums.size();
    long long count = 0;

    map<int, int> windowMap;

    while (j < n)
    {
      windowMap[nums[j]]++;

      while (windowMap.rbegin()->first - windowMap.begin()->first > 2)
      {
        windowMap[nums[i]]--;

        if (windowMap[nums[i]] == 0)
          windowMap.erase(nums[i]);

        i++;
      }

      count += j - i + 1;

      j++;
    }

    return count;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 4, 6, 6, 8};

  cout << sol.continuousSubarraysBrute(nums) << endl;
  cout << sol.continuousSubarraysOptimal(nums) << endl;

  return 0;
}