#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    int fiveBills = 0, tenBills = 0;

    for (int bill : bills)
    {
      if (bill == 5)
        fiveBills++;
      else if (bill == 10)
      {
        if (fiveBills)
          fiveBills--;
        else
          return false;

        tenBills++;
      }
      else
      {
        if (fiveBills && tenBills)
        {
          fiveBills--;
          tenBills--;
        }
        else if (fiveBills >= 3)
          fiveBills -= 3;
        else
          return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> bills = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};

  cout << sol.lemonadeChange(bills);

  return 0;
}