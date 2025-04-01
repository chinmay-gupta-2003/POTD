#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findComplement(int num)
  {
    int lastSetBit = -1;
    for (int i = 0; i <= 31; i++)
    {
      if ((1 << i) & num)
        lastSetBit = i;
    }

    for (int i = 0; i <= lastSetBit; i++)
      num ^= (1 << i);

    return num;
  }
};

int main()
{
  Solution sol;
  int num = 5;

  cout << sol.findComplement(num);

  return 0;
}