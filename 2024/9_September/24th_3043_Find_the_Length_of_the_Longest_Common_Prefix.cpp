#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestCommonPrefixBrute(vector<int> &arr1, vector<int> &arr2)
  {
    int n1 = arr1.size(), n2 = arr2.size();

    int result = 0;

    for (int i = 0; i < n1; i++)
    {
      for (int j = 0; j < n2; j++)
      {
        string num_1 = to_string(arr1[i]);
        string num_2 = to_string(arr2[j]);

        int prefixLength = 0;

        while (prefixLength < min(num_1.length(), num_2.length()) && num_1[prefixLength] == num_2[prefixLength])
          prefixLength++;

        result = max(result, prefixLength);
      }
    }

    return result;
  }

  int longestCommonPrefixBetter(vector<int> &arr1, vector<int> &arr2)
  {
    int n1 = arr1.size(), n2 = arr2.size();

    unordered_set<int> s;

    for (int i = 0; i < n1; i++)
    {
      int num = arr1[i];

      while (!s.count(num) && num > 0)
      {
        s.insert(num);

        num /= 10;
      }
    }

    int result = 0;

    for (int i = 0; i < n2; i++)
    {
      int num = arr2[i];

      while (num > 0)
      {
        if (s.count(num))
          result = max(result, (int)to_string(num).length());

        num /= 10;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> arr1 = {1, 10, 100}, arr2 = {1000};

  cout << sol.longestCommonPrefixBrute(arr1, arr2) << endl;
  cout << sol.longestCommonPrefixBetter(arr1, arr2) << endl;

  return 0;
}