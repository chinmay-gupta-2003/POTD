#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isUgly(int n)
  {
    int i = 2;

    while (n != 1)
    {
      while (n % i == 0)
        n = n / i;

      if (n == 1)
        return true;

      i++;

      if (i > 5)
        return false;
    }

    return true;
  }

  int nthUglyNumberBrute(int n)
  {
    int result = 1, count = 0;

    while (count < n)
    {
      if (isUgly(result))
        count++;

      if (count == n)
        return result;

      result++;
    }

    return result;
  }

  int nthUglyNumberOptimal(int n)
  {
    int p2 = 1, p3 = 1, p5 = 1;

    vector<int> result(n + 1, 0);

    result[1] = 1;

    for (int i = 2; i <= n; i++)
    {
      int numFromTwo = result[p2] * 2;
      int numFromThree = result[p3] * 3;
      int numFromFive = result[p5] * 5;

      int minNum = min({numFromTwo, numFromThree, numFromFive});

      result[i] = minNum;

      if (numFromTwo == minNum)
        p2++;

      if (numFromThree == minNum)
        p3++;

      if (numFromFive == minNum)
        p5++;
    }

    return result[n];
  }
};

int main()
{
  Solution sol;
  int n = 10;

  cout << sol.nthUglyNumberBrute(n) << endl;
  cout << sol.nthUglyNumberOptimal(n) << endl;

  return 0;
}