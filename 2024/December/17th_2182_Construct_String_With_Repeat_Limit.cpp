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

  string repeatLimitedStringApproach2(string s, int repeatLimit)
  {
    vector<int> freqArray(26, 0);

    for (auto it : s)
      freqArray[it - 'a']++;

    priority_queue<char> pq;

    for (int i = 0; i < 26; i++)
    {
      if (freqArray[i])
        pq.push(i + 'a');
    }

    string result = "";

    while (!pq.empty())
    {
      char top = pq.top();
      pq.pop();

      int minFrequency = min(freqArray[top - 'a'], repeatLimit);

      result += string(minFrequency, top);
      freqArray[top - 'a'] -= minFrequency;

      if (freqArray[top - 'a'] > 0 && !pq.empty())
      {

        char nextChar = pq.top();

        result += nextChar;
        freqArray[nextChar - 'a']--;

        if (freqArray[nextChar - 'a'] == 0)
          pq.pop();

        pq.push(top);
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
  cout << sol.repeatLimitedStringApproach2(s, repeatingLimit) << endl;

  return 0;
}