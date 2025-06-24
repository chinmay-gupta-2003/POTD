#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    unordered_map<int, int> memoryMap;

    for (int i = 0; i < n; i++)
    {
      int remainingTarget = target - nums[i];

      if (memoryMap.find(remainingTarget) != memoryMap.end())
        return {memoryMap[remainingTarget], i};

      memoryMap[nums[i]] = i;
    }

    return {-1, -1};
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {2, 7, 11, 15};
  int target = 17;

  vector<int> ans = sol.twoSum(nums, target);

  cout << ans[0] << ", " << ans[1];

  return 0;
}