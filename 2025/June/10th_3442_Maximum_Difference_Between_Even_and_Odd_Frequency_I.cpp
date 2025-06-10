#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDifference(string s)
  {
    vector<int> freq(26, 0);

    int maxOddFreq = 0, minEvenFreq = 1e3;

    for (char &ch : s)
      freq[ch - 'a']++;

    for (int i = 0; i <= 25; i++)
    {
      if (freq[i] % 2)
        maxOddFreq = max(maxOddFreq, freq[i]);
      else if (freq[i] > 0)
        minEvenFreq = min(minEvenFreq, freq[i]);
    }

    return maxOddFreq - minEvenFreq;
  }
};

int main()
{
  Solution sol;
  string s = "aaaaabbc";

  cout << sol.maxDifference(s) << endl;

  return 0;
}