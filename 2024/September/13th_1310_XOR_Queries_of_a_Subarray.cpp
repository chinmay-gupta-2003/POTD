#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> xorQueriesBrute(vector<int> &arr, vector<vector<int>> &queries)
  {
    vector<int> result;

    for (auto range : queries)
    {
      int xorVal = 0;

      for (int i = range[0]; i <= range[1]; i++)
        xorVal ^= arr[i];

      result.push_back(xorVal);
    }

    return result;
  }

  vector<int> xorQueriesBetter(vector<int> &arr, vector<vector<int>> &queries)
  {
    int xorVal = 0;
    vector<int> xorArr;

    for (int val : arr)
    {
      xorVal ^= val;

      xorArr.push_back(xorVal);
    }

    vector<int> result;

    for (auto range : queries)
    {
      int left = range[0], right = range[1];

      int xorVal = xorArr[right];

      if (left > 0)
        xorVal ^= xorArr[left - 1];

      result.push_back(xorVal);
    }

    return result;
  }

  vector<int> xorQueriesOptimal(vector<int> &arr, vector<vector<int>> &queries)
  {
    int n = arr.size();

    for (int i = 1; i < n; i++)
      arr[i] ^= arr[i - 1];

    vector<int> result;

    for (auto range : queries)
    {
      int left = range[0], right = range[1];

      int xorVal = arr[right];

      if (left > 0)
        xorVal ^= arr[left - 1];

      result.push_back(xorVal);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 3, 4, 8};
  vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};

  auto ans = sol.xorQueriesBrute(arr, queries);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.xorQueriesBetter(arr, queries);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.xorQueriesOptimal(arr, queries);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  return 0;
}