#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countFairPairsBrute(vector<int> &nums, int lower, int upper)
  {
    int n = nums.size();
    long long fairPairs = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        long long sum = nums[i] + nums[j];

        if (sum >= lower && sum <= upper)
          fairPairs++;
      }
    }

    return fairPairs;
  }

  long long countFairPairs(vector<int> &nums, int lower, int upper)
  {
    int n = nums.size();
    long long fairPairs = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
      int lowerBoundIndex = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
      int x = lowerBoundIndex - i - 1;

      int upperBoundIdx = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
      int y = upperBoundIdx - i - 1;

      fairPairs += y - x;
    }

    return fairPairs;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {0, 1, 7, 4, 4, 5};
  int lower = 3, upper = 6;

  cout << sol.countFairPairsBrute(nums, lower, upper) << endl;
  cout << sol.countFairPairs(nums, lower, upper) << endl;

  return 0;
}