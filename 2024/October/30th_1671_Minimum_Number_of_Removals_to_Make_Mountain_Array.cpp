#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void longestIncreasingSubsequence(vector<int> &nums, vector<int> &lisDp)
  {
    int n = nums.size();

    for (int ind = 0; ind < n; ind++)
    {
      for (int prevInd = 0; prevInd < ind; prevInd++)
      {
        if (nums[ind] > nums[prevInd])
          lisDp[ind] = max(lisDp[ind], 1 + lisDp[prevInd]);
      }
    }
  }

  void longestDecreasingSubsequence(vector<int> &nums, vector<int> &ldsDp)
  {
    int n = nums.size();

    for (int ind = n - 1; ind >= 0; ind--)
    {
      for (int prevInd = n - 1; prevInd > ind; prevInd--)
      {
        if (nums[ind] > nums[prevInd])
          ldsDp[ind] = max(ldsDp[ind], 1 + ldsDp[prevInd]);
      }
    }
  }

  int minimumMountainRemovals(vector<int> &nums)
  {
    int n = nums.size(), mini = INT_MAX;
    vector<int> lisDp(n, 1), ldsDp(n, 1);

    longestIncreasingSubsequence(nums, lisDp);
    longestDecreasingSubsequence(nums, ldsDp);

    for (int i = 0; i < n; i++)
    {
      int size = lisDp[i] + ldsDp[i] - 1;

      if (size >= 3)
        mini = min(mini, n - size);
    }

    return mini;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 1};

  cout << sol.minimumMountainRemovals(nums) << endl;

  return 0;
}