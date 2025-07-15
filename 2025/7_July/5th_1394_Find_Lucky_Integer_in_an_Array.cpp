#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findLucky(vector<int> &arr)
  {
    map<int, int> freqMap;

    for (int num : arr)
    {
      freqMap[num]++;
    }

    int result = -1;

    for (auto it : freqMap)
    {
      if (it.first == it.second)
        result = it.first;
    }

    return result;
  }

  int findLuckyOptimal(vector<int> &arr)
  {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int result = -1, freq = 1;

    for (int i = 1; i < n; i++)
    {
      if (arr[i] == arr[i - 1])
        freq++;
      else
      {
        if (freq == arr[i - 1])
          result = arr[i - 1];

        freq = 1;
      }
    }

    if (freq == arr[n - 1])
      result = arr[n - 1];

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 2, 3, 3, 3};

  cout << sol.findLucky(arr) << endl;
  cout << sol.findLuckyOptimal(arr) << endl;

  return 0;
}