#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void sieve(vector<bool> &isPrime)
  {
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < 1000; i++)
    {
      if (isPrime[i])
      {
        for (int j = i * i; j < 1000; j += i)
          isPrime[j] = false;
      }
    }
  }

  bool primeSubOperation(vector<int> &nums)
  {
    vector<bool> isPrime(1000, true);

    sieve(isPrime);

    for (int i = nums.size() - 2; i >= 0; i--)
    {
      if (nums[i] < nums[i + 1])
        continue;

      for (int p = 2; p < nums[i]; p++)
      {
        if (!isPrime[p])
          continue;

        if (nums[i] - p < nums[i + 1])
        {
          nums[i] -= p;
          break;
        }
      }

      if (nums[i] >= nums[i + 1])
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 8, 1};

  cout << sol.primeSubOperation(nums);

  return 0;
}