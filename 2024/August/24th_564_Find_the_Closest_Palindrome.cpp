#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long getPalindrone(long number, bool isEven)
  {
    long palindrone = number;

    if (!isEven)
      number /= 10;

    while (number)
    {
      palindrone = palindrone * 10 + number % 10;
      number /= 10;
    }

    return palindrone;
  }

  string nearestPalindromic(string n)
  {
    long length = n.length();

    long mid = length / 2;

    long firstHalfLength = length % 2 ? mid + 1 : mid;

    long firstHalf = stol(n.substr(0, firstHalfLength));

    vector<long> palindrones;

    palindrones.push_back(getPalindrone(firstHalf, length % 2 == 0));
    palindrones.push_back(getPalindrone(firstHalf + 1, length % 2 == 0));
    palindrones.push_back(getPalindrone(firstHalf - 1, length % 2 == 0));
    palindrones.push_back((long)pow(10, length) + 1);
    palindrones.push_back((long)pow(10, length - 1) - 1);

    long minDiff = LONG_MAX;
    long result = LONG_MAX;

    for (int i = 0; i < 5; i++)
    {
      if (palindrones[i] == stol(n))
        continue;

      long diff = abs(stol(n) - palindrones[i]);

      if (diff < minDiff)
      {
        result = palindrones[i];
        minDiff = diff;
      }
      else if (diff == minDiff)
        result = min(result, palindrones[i]);
    }

    return to_string(result);
  }
};

int main()
{
  Solution sol;
  string n = "11";

  cout << sol.nearestPalindromic(n);

  return 0;
}