#include <bits/stdc++.h>
using namespace std;

class FindSumPairsBrute
{
public:
  int n1, n2;
  vector<int> nums1, nums2;

  FindSumPairsBrute(vector<int> &nums1, vector<int> &nums2)
  {
    n1 = nums1.size();
    n2 = nums2.size();

    this->nums1 = nums1;
    this->nums2 = nums2;
  }

  void add(int index, int val) { nums2[index] += val; }

  int count(int tot)
  {
    int count = 0;

    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < n2; j++)
      {
        if (nums1[i] + nums2[j] == tot)
          count++;
      }
    }

    return count;
  }
};

class FindSumPairs
{
public:
  int n1, n2;
  vector<int> nums1, nums2;
  unordered_map<int, int> freqMap;

  FindSumPairs(vector<int> &nums1, vector<int> &nums2)
  {
    n1 = nums1.size();
    n2 = nums2.size();

    this->nums1 = nums1;
    this->nums2 = nums2;

    for (int num : nums2)
    {
      freqMap[num]++;
    }
  }

  void add(int index, int val)
  {
    freqMap[nums2[index]]--;

    nums2[index] += val;

    freqMap[nums2[index]]++;
  }

  int count(int tot)
  {
    int count = 0;

    for (int i = 0; i < n1; i++)
    {
      int x = tot - nums1[i];

      if (freqMap.find(x) != freqMap.end())
        count += freqMap[x];
    }

    return count;
  }
};

int main()
{
  return 0;
}