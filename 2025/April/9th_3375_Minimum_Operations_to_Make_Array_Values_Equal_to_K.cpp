#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperationsBrute(vector<int> &nums, int k)
  {
    sort(nums.begin(), nums.end());

    int n = nums.size();
    int result = 0;

    if (nums[0] < k)
      return -1;

    for (int i = 0; i < n - 1; i++)
    {

      if (nums[i] != nums[i + 1])
        result++;
    }

    if (nums[0] > k)
      result++;

    return result;
  }

  int minOperationsOptimal(vector<int> &nums, int k)
  {
    int n = nums.size();
    unordered_set<int> uniqueNums;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] < k)
        return -1;

      if (nums[i] > k)
        uniqueNums.insert(nums[i]);
    }

    return uniqueNums.size();
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 2, 5, 4, 5};
  int k = 2;

  cout << sol.minOperationsBrute(nums, k) << endl;
  cout << sol.minOperationsOptimal(nums, k) << endl;

  return 0;
}