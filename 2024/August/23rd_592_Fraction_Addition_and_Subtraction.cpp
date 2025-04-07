#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string fractionAddition(string expression)
  {
    int i = 0, n = expression.length();
    int resultantNumerator = 0, resultantDenominator = 1;

    while (i < n)
    {
      int numerator = 0, denominator = 0;

      bool isNegative = (expression[i] == '-');

      if (expression[i] == '+' || expression[i] == '-')
        i++;

      while (i < n && isdigit(expression[i]))
      {
        int digit = expression[i] - '0';

        numerator = numerator * 10 + digit;
        i++;
      }

      if (isNegative)
        numerator *= -1;

      i++;

      while (i < n && isdigit(expression[i]))
      {
        int digit = expression[i] - '0';

        denominator = denominator * 10 + digit;
        i++;
      }

      resultantNumerator = numerator * resultantDenominator + resultantNumerator * denominator;
      resultantDenominator *= denominator;
    }

    int GCD = abs(__gcd(resultantNumerator, resultantDenominator));

    return to_string(resultantNumerator / GCD) + '/' + to_string(resultantDenominator / GCD);
  }
};

int main()
{
  Solution sol;
  string expression = "-1/3+1/2";

  cout << sol.fractionAddition(expression);

  return 0;
}