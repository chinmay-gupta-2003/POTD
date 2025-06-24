#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getMaximumXorBrute(vector<int> &nums, int maximumBit)
  {
    int xorVal = 0;
    int n = nums.size();
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
      xorVal ^= nums[i];

      int maxK = 0, maxXor = INT_MIN;

      for (int k = 0; k < pow(2, maximumBit); k++)
      {
        if ((xorVal ^ k) > maxXor)
        {
          maxXor = xorVal ^ k;
          maxK = k;
        }
      }

      ans[n - 1 - i] = maxK;
    }

    return ans;
  }

  vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
  {
    int n = nums.size();
    vector<int> ans(n);

    int xorVal = 0;

    for (int i = 0; i < n; i++)
    {
      xorVal ^= nums[i];

      int mask = (1 << maximumBit) - 1;

      int k = xorVal ^ mask;

      ans[n - 1 - i] = k;
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {0, 1, 1, 3};
  int maximumBit = 2;

  auto ans = sol.getMaximumXorBrute(nums, maximumBit);
  for (auto it : nums)
    cout << it << " ";

  cout << endl;

  ans = sol.getMaximumXor(nums, maximumBit);
  for (auto it : nums)
    cout << it << " ";

  return 0;
}