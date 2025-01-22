#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minBitFlips(int start, int goal)
  {
    int result = 0;
    int diff = start ^ goal;

    for (int i = 0; i < 31; i++)
    {
      if (diff & (1 << i))
        result++;
    }

    return result;
  }
};

int main()
{
  Solution sol;

  cout << sol.minBitFlips(10, 7);

  return 0;
}