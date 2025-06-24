#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int differenceOfSumsBrute(int n, int m)
  {
    int num1 = 0, num2 = 0;

    for (int i = 1; i <= n; i++)
    {
      if (i % m)
        num1 += i;
      else
        num2 += i;
    }

    return num1 - num2;
  }

  int differenceOfSumsOptimal(int n, int m)
  {
    int num1 = 0, num2 = 0;

    int numElementsInM = n / m;

    num2 = m * (numElementsInM) * (numElementsInM + 1) / 2;

    num1 = n * (n + 1) / 2 - num2;

    return num1 - num2;
  }
};

int main()
{
  Solution sol;
  int n = 10, m = 3;

  cout << sol.differenceOfSumsBrute(n, m) << endl;
  cout << sol.differenceOfSumsOptimal(n, m) << endl;

  return 0;
}