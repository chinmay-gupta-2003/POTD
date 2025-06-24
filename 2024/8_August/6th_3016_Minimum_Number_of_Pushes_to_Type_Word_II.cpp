#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumPushes(string word)
  {
    vector<int> charFreq(26, 0);

    for (char &ch : word)
      charFreq[ch - 'a']++;

    sort(charFreq.begin(), charFreq.end(), greater<int>());

    int result = 0;

    for (int i = 0; i < 26; i++)
    {
      if (charFreq[i] == 0)
        break;

      result += (i / 8 + 1) * charFreq[i];
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string word = "abcde";

  cout << sol.minimumPushes(word) << endl;

  return 0;
}