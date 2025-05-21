#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numWaterBottles(int numBottles, int numExchange)
  {
    int bottlesDrank = numBottles, emptyBottles = numBottles;

    while (emptyBottles >= numExchange)
    {
      emptyBottles = emptyBottles - numExchange + 1;
      bottlesDrank++;
    }

    return bottlesDrank;
  }

  int numWaterBottlesOptimal(int numBottles, int numExchange)
  {
    return numBottles + (numBottles - 1) / (numExchange - 1);
  }
};

int main()
{
  Solution sol;
  int numBottles = 9, numExchange = 5;

  cout << sol.numWaterBottles(numBottles, numExchange) << endl;
  cout << sol.numWaterBottlesOptimal(numBottles, numExchange) << endl;

  return 0;
}