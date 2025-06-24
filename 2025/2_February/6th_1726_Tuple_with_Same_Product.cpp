#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int tupleSameProduct(vector<int> &nums)
  {
    int n = nums.size();

    unordered_map<int, int> freqMap;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
        freqMap[nums[i] * nums[j]]++;
    }

    int result = 0;

    for (auto it : freqMap)
    {
      if (it.second > 1)
        result += it.second * (it.second - 1) * 4;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};

  cout << sol.tupleSameProduct(nums) << endl;

  return 0;
}