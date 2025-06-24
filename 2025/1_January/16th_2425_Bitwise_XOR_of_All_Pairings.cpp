#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int xorAllNumsBrute(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();

    int result = 0;

    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < n2; j++)
        result ^= nums1[i] ^ nums2[j];
    }

    return result;
  }

  int xorAllNumsBetter(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();
    int xorNums1 = 0, xorNums2 = 0;

    for (int i = 0; i < n1; i++)
      xorNums1 ^= nums1[i];

    for (int j = 0; j < n2; j++)
      xorNums2 ^= nums2[j];

    int result = 0;

    for (int j = 0; j < n2; j++)
      result ^= xorNums1;

    for (int i = 0; i < n1; i++)
      result ^= xorNums2;

    return result;
  }

  int xorAllNumsOptimal(vector<int> &nums1, vector<int> &nums2)
  {
    int n1 = nums1.size(), n2 = nums2.size();

    int result = 0;

    if (n2 % 2)
    {
      for (int i = 0; i < n1; i++)
        result ^= nums1[i];
    }

    if (n1 % 2)
    {
      for (int j = 0; j < n2; j++)
        result ^= nums2[j];
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {2, 1, 3}, nums2 = {10, 2, 5, 0};

  cout << sol.xorAllNumsBrute(nums1, nums2) << endl;
  cout << sol.xorAllNumsBetter(nums1, nums2) << endl;
  cout << sol.xorAllNumsOptimal(nums1, nums2) << endl;

  return 0;
}