#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool threeConsecutiveOddsMethod1(vector<int> &arr)
  {
    int n = arr.size();
    int i = 0, j = 0;

    while (j < n)
    {
      if (arr[j] % 2 == 0)
        i = j;

      while (i < j && (arr[i] % 2 == 0))
        i++;

      if (j - i >= 2)
        return true;

      j++;
    }

    return false;
  }

  bool threeConsecutiveOddsMethod2(vector<int> &arr)
  {
    int n = arr.size();
    int countOdds = 0;

    for (int i = 0; i < n; i++)
    {
      if (arr[i] % 2)
        countOdds++;
      else
        countOdds = 0;

      if (countOdds == 3)
        return true;
    }

    return false;
  }
};

int main()
{
  Solution sol;

  vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};

  cout << sol.threeConsecutiveOddsMethod1(arr) << endl;
  cout << sol.threeConsecutiveOddsMethod2(arr) << endl;

  return 0;
}
