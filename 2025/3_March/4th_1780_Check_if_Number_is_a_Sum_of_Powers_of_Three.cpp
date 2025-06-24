#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkPowersOfThreeBrute(int n)
  {
    int prevPower = -1;

    while (n)
    {
      int maxPower = 1;

      while (maxPower * 3 <= n)
        maxPower *= 3;

      if (prevPower == maxPower)
        return false;

      prevPower = maxPower;
      n -= maxPower;
    }

    return true;
  }

  bool checkPowersOfThreeOptimal(int n)
  {
    while (n)
    {
      int remainder = n % 3;

      if (remainder > 1)
        return false;

      n = n / 3;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  int n = 13;

  cout << sol.checkPowersOfThreeBrute(n) << endl;
  cout << sol.checkPowersOfThreeOptimal(n) << endl;

  return 0;
}