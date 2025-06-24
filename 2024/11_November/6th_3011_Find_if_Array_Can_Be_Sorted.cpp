#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSetBits(int num)
  {
    int cnt = 0;

    while (num)
    {
      int rem = num % 2;

      if (rem == 1)
        cnt++;

      num /= 2;
    }

    return cnt;
  }

  bool canSortArrayBrute(vector<int> &nums)
  {
    int n = nums.size(), cnt = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n - 1 - i; j++)
      {
        if (nums[j] > nums[j + 1])
        {
          if (countSetBits(nums[j]) == countSetBits(nums[j + 1]))
            swap(nums[j], nums[j + 1]);

          else
            return false;
        }
      }
    }

    return true;
  }

  bool canSortArrayOptimal(vector<int> &nums)
  {
    int n = nums.size();

    int prevMax = INT_MIN;
    int maxi = nums[0], mini = nums[0];
    int setBits = countSetBits(nums[0]);

    for (int i = 0; i < n; i++)
    {
      if (countSetBits(nums[i]) == setBits)
      {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);

        continue;
      }

      if (mini < prevMax)
        return false;

      prevMax = maxi;

      maxi = nums[i];
      mini = nums[i];

      setBits = countSetBits(nums[i]);
    }

    if (mini < prevMax)
      return false;

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {8, 4, 2, 30, 15};

  cout << sol.canSortArrayBrute(nums) << endl;
  cout << sol.canSortArrayOptimal(nums) << endl;

  return 0;
}