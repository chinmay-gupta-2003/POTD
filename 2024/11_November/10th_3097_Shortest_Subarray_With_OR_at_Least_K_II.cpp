#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumSubarrayLengthBrute(vector<int> &nums, int k)
  {
    int n = nums.size();
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      int currOr = 0;
      for (int j = i; j < n; j++)
      {
        currOr |= nums[j];

        if (currOr >= k)
          minLen = min(minLen, j - i + 1);
      }
    }

    return minLen == INT_MAX ? -1 : minLen;
  }

  void addInOR(vector<int> &cntSetBits, int num)
  {
    for (int i = 0; i < cntSetBits.size(); i++)
    {
      if ((1 << i) & num)
        cntSetBits[i]++;
    }
  }

  int getOrDecimal(vector<int> &cntSetBits)
  {
    int num = 0;

    for (int i = 0; i < cntSetBits.size(); i++)
    {
      if (cntSetBits[i] > 0)
        num |= (1 << i);
    }

    return num;
  }

  void removeFromOR(vector<int> &cntSetBits, int num)
  {
    for (int i = 0; i < cntSetBits.size(); i++)
    {
      if ((1 << i) & num)
        cntSetBits[i]--;
    }
  }

  int minimumSubarrayLengthOptimal(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> cntSetBits(32, 0);

    int j = 0, minLen = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      addInOR(cntSetBits, nums[i]);

      while (j <= i && getOrDecimal(cntSetBits) >= k)
      {
        minLen = min(minLen, i - j + 1);

        removeFromOR(cntSetBits, nums[j]);
        j++;
      }
    }

    return minLen == INT_MAX ? -1 : minLen;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 32, 21};
  int k = 55;

  cout << sol.minimumSubarrayLengthBrute(nums, k) << endl;
  cout << sol.minimumSubarrayLengthOptimal(nums, k) << endl;

  return 0;
}