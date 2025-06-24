#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimizeXor(int num1, int num2)
  {
    int setBitsNum1 = 0, setBitsNum2 = 0;
    int temp1 = num1, temp2 = num2;

    while (temp1)
    {
      if (temp1 & 1)
        setBitsNum1++;

      temp1 = temp1 >> 1;
    }

    while (temp2)
    {
      if (temp2 & 1)
        setBitsNum2++;

      temp2 = temp2 >> 1;
    }

    if (setBitsNum1 == setBitsNum2)
      return num1;
    else if (setBitsNum2 > setBitsNum1)
    {
      int i = 0;

      while (setBitsNum2 > setBitsNum1)
      {
        if ((num1 & (1 << i)) == 0)
        {
          num1 = num1 | (1 << i);

          setBitsNum2--;
        }

        i++;
      }
    }
    else
    {
      int i = 0;

      while (setBitsNum1 > setBitsNum2)
      {
        if (num1 & (1 << i))
        {
          num1 = num1 & ~(1 << i);

          setBitsNum1--;
        }

        i++;
      }
    }

    return num1;
  }
};

int main()
{
  Solution sol;
  int num1 = 1, num2 = 12;

  cout << sol.minimizeXor(num1, num2);

  return 0;
}