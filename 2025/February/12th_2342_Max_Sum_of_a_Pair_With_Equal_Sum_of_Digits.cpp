#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int sumDigits(int num)
  {
    int sum = 0;

    while (num)
    {
      sum += num % 10;
      num /= 10;
    }

    return sum;
  }

  int maximumSumBrute(vector<int> &nums)
  {
    int n = nums.size(), result = -1;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (sumDigits(nums[i]) == sumDigits(nums[j]))
          result = max(result, nums[i] + nums[j]);
      }
    }

    return result;
  }

  int maximumSumOptimal(vector<int> &nums)
  {
    int n = nums.size(), result = -1;
    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++)
    {
      int digitSum = sumDigits(nums[i]);

      if (freqMap.find(digitSum) != freqMap.end())
      {
        result = max(result, nums[i] + freqMap[digitSum]);

        freqMap[digitSum] = max(freqMap[digitSum], nums[i]);
      }
      else
        freqMap[digitSum] = nums[i];
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {18, 43, 36, 13, 7};

  cout << sol.maximumSumBrute(nums) << endl;
  cout << sol.maximumSumOptimal(nums) << endl;

  return 0;
}