#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isZeroArrayBrute(vector<int> &nums, vector<vector<int>> &queries)
  {
    for (auto range : queries)
    {
      int start = range[0], end = range[1];

      for (int i = start; i <= end; i++)
      {
        if (nums[i] > 0)
          nums[i]--;
      }
    }

    for (int num : nums)
    {
      if (num > 0)
        return false;
    }

    return true;
  }

  bool isZeroArrayOptimal(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();

    vector<int> zeroArray(n, 0);

    for (auto range : queries)
    {
      int start = range[0], end = range[1];

      zeroArray[start] += 1;

      if (end < n - 1)
        zeroArray[end + 1] -= 1;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (i > 0)
        zeroArray[i] = zeroArray[i - 1] + zeroArray[i];

      if (nums[i] > zeroArray[i])
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 3, 2, 1};
  vector<vector<int>> queries = {{1, 3}, {0, 2}};

  cout << sol.isZeroArrayBrute(nums, queries) << endl;

  return 0;
}