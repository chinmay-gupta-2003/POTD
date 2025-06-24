#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool threeConsecutiveOdds(vector<int> &arr)
  {
    int oddsCount = 0;

    for (int num : arr)
    {
      if (num % 2)
        oddsCount++;
      else
        oddsCount = 0;

      if (oddsCount == 3)
        return true;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 34, 3, 4, 5, 7, 23, 12};

  cout << sol.threeConsecutiveOdds(arr);

  return 0;
}