#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findEvenNumbersBrute(vector<int> &digits)
  {
    int n = digits.size();
    set<int> uniqueNumbers;

    for (int i = 0; i < n; i++)
    {
      int singleDigit = digits[i];

      if (singleDigit == 0)
        continue;

      for (int j = 0; j < n; j++)
      {
        if (j == i)
          continue;

        int doubleDigit = singleDigit * 10 + digits[j];

        for (int k = 0; k < n; k++)
        {
          if (k == i || k == j)
            continue;

          int trippleDigit = doubleDigit * 10 + digits[k];

          if (trippleDigit % 2 == 0)
            uniqueNumbers.insert(trippleDigit);
        }
      }
    }

    vector<int> result(uniqueNumbers.begin(), uniqueNumbers.end());

    return result;
  }

  vector<int> findEvenNumbersOptimal(vector<int> &digits)
  {
    vector<int> digitFrequency(10, 0);

    for (int digit : digits)
      digitFrequency[digit]++;

    vector<int> result;

    for (int i = 1; i <= 9; i++)
    {
      if (digitFrequency[i] == 0)
        continue;

      digitFrequency[i]--;

      for (int j = 0; j <= 9; j++)
      {
        if (digitFrequency[j] == 0)
          continue;

        digitFrequency[j]--;

        int doubleDigit = i * 10 + j;

        for (int k = 0; k <= 8; k += 2)
        {
          if (digitFrequency[k] == 0)
            continue;

          digitFrequency[k]--;

          int trippleDigit = doubleDigit * 10 + k;

          result.push_back(trippleDigit);

          digitFrequency[k]++;
        }

        digitFrequency[j]++;
      }

      digitFrequency[i]++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> digits = {2, 1, 3, 0};

  auto ans = sol.findEvenNumbersBrute(digits);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.findEvenNumbersOptimal(digits);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}