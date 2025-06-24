#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void solve(vector<vector<int>> &subsets, vector<int> subset, vector<int> &nums, int index)
  {
    if (index == nums.size())
      return subsets.push_back(subset);

    subset.push_back(nums[index]);
    solve(subsets, subset, nums, index + 1);

    subset.pop_back();
    solve(subsets, subset, nums, index + 1);
  }

  int subsetXORSumBrute(vector<int> &nums)
  {
    vector<vector<int>> subsets;

    solve(subsets, {}, nums, 0);

    int XORSum = 0;

    for (int i = 0; i < subsets.size(); i++)
    {
      int XOR = 0;

      for (int j = 0; j < subsets[i].size(); j++)
        XOR ^= subsets[i][j];

      XORSum += XOR;
    }

    return XORSum;
  }

  int solveBetter(vector<int> &nums, int XOR, int index)
  {
    if (index == nums.size())
      return XOR;

    int include = solveBetter(nums, nums[index] ^ XOR, index + 1);
    int exclude = solveBetter(nums, XOR, index + 1);

    return include + exclude;
  }

  int subsetXORSumBetter(vector<int> &nums)
  {
    return solveBetter(nums, 0, 0);
  }

  int subsetXORSumOptimal(vector<int> &nums)
  {
    int n = nums.size();
    int result = 0;

    for (int num : nums)
      result |= num;

    return result << (n - 1);
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 1, 6};

  cout << sol.subsetXORSumBrute(nums) << endl;
  cout << sol.subsetXORSumBetter(nums) << endl;
  cout << sol.subsetXORSumOptimal(nums) << endl;

  return 0;
}