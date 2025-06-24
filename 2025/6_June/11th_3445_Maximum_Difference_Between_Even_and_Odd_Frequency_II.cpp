#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDifferenceBrute(string s, int k)
  {
    int n = s.length(), maxDiff = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      vector<int> freq(5, 0);

      for (int j = i; j < n; j++)
      {
        freq[s[j] - '0']++;

        if (j - i + 1 >= k)
        {
          int maxOddFreq = 0, minEvenFreq = INT_MAX;

          for (int l = 0; l < 5; l++)
          {
            if (freq[l] == 0)
              continue;

            if (freq[l] % 2)
              maxOddFreq = max(maxOddFreq, freq[l]);
            else
              minEvenFreq = min(minEvenFreq, freq[l]);
          }

          if (maxOddFreq != 0 && minEvenFreq != INT_MAX)
            maxDiff = max(maxDiff, maxOddFreq - minEvenFreq);
        }
      }
    }

    return maxDiff;
  }

  int getState(int a, int b)
  {
    int remainder_a = a % 2;
    int remainder_b = b % 2;

    if (remainder_a && remainder_b)
      return 3;

    if (remainder_a && !remainder_b)
      return 2;

    if (!remainder_a && remainder_b)
      return 1;

    return 0;
  }

  int maxDifferenceOptimal(string s, int k)
  {
    int n = s.length(), maxDiff = INT_MIN;

    for (char a = '0'; a <= '4'; a++)
    {
      for (char b = '0'; b <= '4'; b++)
      {
        if (a == b)
          continue;

        int count_a = 0, count_b = 0;
        int prevCount_a = 0, prevCount_b = 0;

        vector<int> minPrevCount(4, INT_MAX);

        int r = 0, l = -1;

        while (r < n)
        {
          count_a += (s[r] == a) ? 1 : 0;
          count_b += (s[r] == b) ? 1 : 0;

          while (r - l >= k && count_a - prevCount_a >= 1 && count_b - prevCount_b >= 2)
          {
            int leftState = getState(prevCount_a, prevCount_b);

            minPrevCount[leftState] = min(minPrevCount[leftState], prevCount_a - prevCount_b);

            l++;

            prevCount_a += (s[l] == a) ? 1 : 0;
            prevCount_b += (s[l] == b) ? 1 : 0;
          }

          int state = getState(count_a, count_b);
          int leftState = state ^ 2;

          int leftStateMinVal = minPrevCount[leftState];

          if (leftStateMinVal != INT_MAX)
            maxDiff = max(maxDiff, count_a - count_b - leftStateMinVal);

          r++;
        }
      }
    }

    return maxDiff;
  }
};

int main()
{
  Solution sol;

  int k = 2;
  string s = "300";

  cout << sol.maxDifferenceBrute(s, k) << endl;
  cout << sol.maxDifferenceOptimal(s, k) << endl;

  return 0;
}