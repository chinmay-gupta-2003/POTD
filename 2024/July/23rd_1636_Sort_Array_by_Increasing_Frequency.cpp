#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> frequencySort(vector<int> &nums)
  {
    unordered_map<int, int> freqMap;

    for (int num : nums)
      freqMap[num]++;

    sort(nums.begin(), nums.end(), [&](int a, int b)
         {
      if (freqMap[a] == freqMap[b]) return a > b;
          
      return freqMap[a] < freqMap[b]; });

    return nums;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 1, 3, 2};

  auto ans = sol.frequencySort(nums);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}
