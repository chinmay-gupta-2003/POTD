#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int partitionArray(vector<int> &nums, int k)
  {
    int n = nums.size(), result = 1;

    sort(nums.begin(), nums.end());

    if (nums[n - 1] - nums[0] <= k)
      return result;
    else
      result++;

    int lastMax = nums[n - 1];

    for (int i = n - 2; i >= 1; i--)
    {
      if (nums[i] - nums[0] > k && lastMax - nums[i] > k)
      {
        result++;
        lastMax = nums[i];
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {3, 6, 1, 2, 5};
  int k = 2;

  cout << sol.partitionArray(nums, k) << endl;

  return 0;
}