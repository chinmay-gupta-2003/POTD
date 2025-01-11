#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canConstruct(string s, int k)
  {
    int n = s.length();

    if (n < k)
      return false;

    if (n == k)
      return true;

    int oddFreq = 0;
    vector<int> freq(26, 0);

    for (char ch : s)
      freq[ch - 'a']++;

    for (int it : freq)
    {
      if (it % 2)
        oddFreq++;
    }

    return oddFreq <= k;
  }
};

int main()
{
  Solution sol;
  string s = "annabcdelle";
  int k = 2;

  cout << sol.canConstruct(s, k);

  return 0;
}