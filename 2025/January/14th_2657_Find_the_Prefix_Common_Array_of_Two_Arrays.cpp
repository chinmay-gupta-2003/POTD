#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findThePrefixCommonArrayBetter(vector<int> &A, vector<int> &B)
  {
    int n = A.size();

    vector<int> freq(n + 1, 0), result(n, 0);

    for (int i = 0; i < n; i++)
    {
      freq[A[i]]++;
      freq[B[i]]++;

      for (int j = 1; j <= n; j++)
      {
        if (freq[j] == 2)
          result[i]++;
      }
    }

    return result;
  }

  vector<int> findThePrefixCommonArrayOptimal(vector<int> &A, vector<int> &B)
  {
    int n = A.size();

    unordered_map<int, int> freqMap;
    int count = 0;

    vector<int> result(n, 0);

    for (int i = 0; i < n; i++)
    {
      freqMap[A[i]]++;
      if (freqMap[A[i]] == 2)
        count++;

      freqMap[B[i]]++;
      if (freqMap[B[i]] == 2)
        count++;

      result[i] = count;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> A = {1, 3, 2, 4}, B = {3, 1, 2, 4};

  auto ans = sol.findThePrefixCommonArrayBetter(A, B);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.findThePrefixCommonArrayOptimal(A, B);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}