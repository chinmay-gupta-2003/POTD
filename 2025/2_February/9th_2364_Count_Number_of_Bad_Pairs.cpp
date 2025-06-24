#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long countBadPairsBrute(vector<int> &nums)
  {
    int n = nums.size();

    long long result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (j - i != nums[j] - nums[i])
          result++;
      }
    }

    return result;
  }

  long long countBadPairsOptimal(vector<int> &nums)
  {
    int n = nums.size();

    long long result = 0;

    unordered_map<int, int> visitedNums;

    for (int i = 0; i < n; i++)
    {
      result += i - visitedNums[nums[i] - i];

      visitedNums[nums[i] - i]++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 1, 3, 3};

  cout << sol.countBadPairsBrute(nums) << endl;
  cout << sol.countBadPairsOptimal(nums) << endl;

  return 0;
}