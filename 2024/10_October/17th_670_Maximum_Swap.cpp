#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumSwapBrute(int num)
  {
    string s = to_string(num);
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
      int maxInd = -1;
      char maxEle = s[i];

      for (int j = i + 1; j < n; j++)
      {
        if (s[j] >= maxEle)
        {
          maxEle = s[j];
          maxInd = j;
        }
      }

      if (maxInd != -1 && maxEle != s[i])
      {
        swap(s[maxInd], s[i]);
        break;
      }
    }

    return stoi(s);
  }

  int maximumSwapBetter(int num)
  {
    string s = to_string(num);
    int n = s.length();

    vector<int> maxRight(n);
    maxRight[n - 1] = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
      if (s[i] <= s[maxRight[i + 1]])
        maxRight[i] = maxRight[i + 1];
      else
        maxRight[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
      if (s[i] != s[maxRight[i]])
      {
        swap(s[i], s[maxRight[i]]);
        break;
      }
    }

    return stoi(s);
  }

  int maximumSwapOptimal(int num)
  {
    string s = to_string(num);
    int n = s.length();

    int swap1 = -1, swap2 = -1;
    int maxEle = s[n - 1], maxEleIndex = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
      if (s[i] > maxEle)
      {
        maxEle = s[i];
        maxEleIndex = i;
      }
      else if (s[i] < maxEle)
      {
        swap1 = i;
        swap2 = maxEleIndex;
      }
    }

    if (swap1 != -1)
      swap(s[swap1], s[swap2]);

    return stoi(s);
  }
};

int main()
{
  Solution sol;
  int num = 1993;

  cout << sol.maximumSwapBrute(num) << endl;
  cout << sol.maximumSwapBetter(num) << endl;
  cout << sol.maximumSwapOptimal(num) << endl;

  return 0;
}