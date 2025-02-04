#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string kthDistinct(vector<string> &arr, int k)
  {
    unordered_map<string, int> freqMap;

    for (string &word : arr)
      freqMap[word]++;

    for (string &word : arr)
    {
      if (freqMap[word] == 1)
        k--;

      if (k == 0)
        return word;
    }

    return "";
  }
};

int main()
{
  Solution sol;

  vector<string> arr = {"aaa", "aa", "a"};
  int k = 1;

  cout << sol.kthDistinct(arr, k) << endl;

  return 0;
}