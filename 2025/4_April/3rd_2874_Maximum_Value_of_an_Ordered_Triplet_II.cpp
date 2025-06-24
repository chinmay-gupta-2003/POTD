#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maximumTripletValue(vector<int> &nums)
  {
    int maxi = 0, maxDiff = 0;
    long long result = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      result = max(result, (long long)maxDiff * nums[i]);

      maxDiff = max(maxDiff, maxi - nums[i]);

      maxi = max(maxi, nums[i]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {12, 6, 1, 2, 7};

  cout << sol.maximumTripletValue(nums);

  return 0;
}