#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string repeatLimitedStringApproach1(string s, int repeatLimit)
  {
    vector<int> freqArray(26, 0);

    for (auto it : s)
      freqArray[it - 'a']++;

    int i = 25;
    string result = "";

    while (i >= 0)
    {
      if (freqArray[i] == 0)
      {
        i--;
        continue;
      }

      int minFrequency = min(freqArray[i], repeatLimit);

      result += string(minFrequency, 'a' + i);
      freqArray[i] -= minFrequency;

      if (freqArray[i] > 0)
      {
        int j = i - 1;

        while (j >= 0 && freqArray[j] == 0)
          j--;

        if (j < 0)
          break;

        result += 'a' + j;
        freqArray[j]--;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "cczazcc";
  int repeatingLimit = 3;

  cout << sol.repeatLimitedStringApproach1(s, repeatingLimit) << endl;

  return 0;
}