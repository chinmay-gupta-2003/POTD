#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestNiceSubarrayBrute(vector<int> &nums)
  {
    int n = nums.size(), result = 1;

    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
      {
        bool isNice = true;

        for (int k = i; k <= j; k++)
        {
          for (int l = k + 1; l <= j; l++)
          {
            if (nums[k] & nums[l])
            {
              isNice = false;
              break;
            }
          }

          if (!isNice)
            break;
        }

        if (isNice)
          result = max(result, j - i + 1);
      }
    }

    return result;
  }

  int longestNiceSubarrayBetter(vector<int> &nums)
  {
    int n = nums.size(), result = 0;

    for (int i = 0; i < n; i++)
    {
      int onesOR = 0;

      for (int j = i; j < n; j++)
      {
        if (onesOR & nums[j])
          break;

        onesOR |= nums[j];
        result = max(result, j - i + 1);
      }
    }

    return result;
  }

  int longestNiceSubarrayOptimal(vector<int> &nums)
  {
    int n = nums.size();

    int i = 0, j = 0;
    int orMask = 0, result = 0;

    while (j < n)
    {
      while (nums[j] & orMask)
        orMask ^= nums[i++];

      result = max(result, j - i + 1);

      orMask |= nums[j];
      j++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 3, 8, 48, 10};

  cout << sol.longestNiceSubarrayBrute(nums) << endl;
  cout << sol.longestNiceSubarrayBetter(nums) << endl;
  cout << sol.longestNiceSubarrayOptimal(nums) << endl;

  return 0;
}