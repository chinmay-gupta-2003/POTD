#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canBeEqualBetter(vector<int> &target, vector<int> &arr)
  {
    unordered_map<int, int> targetFreqMap, arrFreqMap;

    if (target.size() != arr.size())
      return false;

    for (int num : target)
      targetFreqMap[num]++;

    for (int num : arr)
      arrFreqMap[num]++;

    return targetFreqMap == arrFreqMap;
  }

  bool canBeEqualOptimal(vector<int> &target, vector<int> &arr)
  {
    unordered_map<int, int> freqMap;

    if (target.size() != arr.size())
      return false;

    for (int num : arr)
      freqMap[num]++;

    for (int num : target)
    {
      freqMap[num]--;

      if (freqMap[num] == 0)
        freqMap.erase(num);
    }

    return freqMap.size() == 0;
  }
};

int main()
{
  Solution sol;
  vector<int> target = {1, 2, 4, 4}, arr = {1, 4, 4, 4};

  cout << sol.canBeEqualBetter(target, arr) << endl;
  cout << sol.canBeEqualOptimal(target, arr) << endl;

  return 0;
}