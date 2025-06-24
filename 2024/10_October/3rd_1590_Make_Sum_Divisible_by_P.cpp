#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSubarrayBrute(vector<int> &nums, int p)
  {
    long long n = nums.size();
    long long totalSum = 0;

    for (auto it : nums)
      totalSum += it;

    long long rem = totalSum % p;

    if (rem == 0)
      return 0;

    long long minLen = n;

    for (long long i = 0; i < n; i++)
    {
      long long sum = 0;
      for (long long j = i; j < n; j++)
      {
        sum += nums[j];

        if (sum % p == rem)
          minLen = min(minLen, j - i + 1);
      }
    }

    if (minLen == n)
      return -1;

    return minLen;
  }

  int minSubarrayOptimal(vector<int> &nums, int p)
  {
    long long n = nums.size();
    long long totalSum = 0;

    for (auto it : nums)
      totalSum += it;

    long long rem = totalSum % p;

    if (rem == 0)
      return 0;

    long long minLen = n;
    long long sum = 0;

    unordered_map<long, long> prefixSum;
    prefixSum[0] = -1;

    for (long long i = 0; i < n; i++)
    {
      sum += nums[i];

      int currMod = sum % p;

      int remainingMod = (currMod - rem + p) % p;

      if (prefixSum.find(remainingMod) != prefixSum.end())
        minLen = min(minLen, i - prefixSum[remainingMod]);

      prefixSum[currMod] = i;
    }

    if (minLen == n)
      return -1;

    return minLen;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {26, 19, 11, 14, 18, 4, 7, 1, 30, 23, 19, 8, 10, 6, 26, 3};
  int p = 26;

  cout << sol.minSubarrayBrute(arr, p) << endl;
  cout << sol.minSubarrayOptimal(arr, p) << endl;

  return 0;
}