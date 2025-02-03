#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSwaps(vector<int> &nums)
  {
    int n = nums.size(), totalOnes = 0;

    for (int num : nums)
      totalOnes += num;

    int i = 0, j = 0, currOnes = 0;

    while (j < totalOnes)
      currOnes += nums[j++];

    if (j == n)
      return 0;

    int result = totalOnes - currOnes;

    while (i < n)
    {
      currOnes += nums[j];
      currOnes -= nums[i];

      result = min(result, totalOnes - currOnes);

      i++;
      j = (j + 1) % n;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 1, 0, 1, 0, 0, 1, 1};

  cout << sol.minSwaps(nums);

  return 0;
}