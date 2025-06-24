#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maximumSubarraySum(vector<int> &nums, int k)
  {
    int n = nums.size();
    long long maxSum = 0;

    for (int i = 0; i <= n - k; i++)
    {
      long long sum = 0;
      unordered_set<int> s;

      for (int j = i; j < i + k; j++)
      {
        if (s.find(nums[j]) != s.end())
        {
          sum = 0;
          break;
        }
        else
        {
          sum += nums[j];
          s.insert(nums[j]);
        }
      }

      maxSum = max(maxSum, sum);
    }

    return maxSum;
  }

  long long maximumSubarraySumOptimal(vector<int> &nums, int k)
  {
    int n = nums.size();
    long long maxSum = 0;

    int i = 0, j = 0;
    long long sum = 0;
    unordered_set<int> s;

    while (j < n)
    {
      while (s.find(nums[j]) != s.end())
      {
        sum -= nums[i];
        s.erase(nums[i]);

        i++;
      }

      s.insert(nums[j]);
      sum += nums[j];

      if (j - i + 1 == k)
      {
        maxSum = max(maxSum, sum);

        sum -= nums[i];
        s.erase(nums[i]);

        i++;
      }

      j++;
    }

    return maxSum;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
  int k = 3;

  cout << sol.maximumSubarraySum(nums, k) << endl;
  cout << sol.maximumSubarraySumOptimal(nums, k) << endl;

  return 0;
}