#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int passThePillowBrute(int n, int time)
  {
    int index = 1;
    bool direction = true;

    while (time--)
    {
      if (direction)
        index++;
      else
        index--;

      if (index == n)
        direction = false;

      if (index == 1)
        direction = true;
    }

    return index;
  }

  int passThePillowOptimal(int n, int time)
  {
    int fullRounds = time / (n - 1);
    int remainingTime = time % (n - 1);

    if (fullRounds % 2)
      return n - remainingTime;

    return remainingTime + 1;
  }
};

int main()
{
  Solution sol;
  int n = 4, time = 5;

  cout << sol.passThePillowBrute(n, time) << endl;
  cout << sol.passThePillowOptimal(n, time) << endl;

  return 0;
}