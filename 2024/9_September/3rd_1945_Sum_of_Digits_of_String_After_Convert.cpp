#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getLucky(string &s, int k)
  {
    string converted = "";

    for (char ch : s)
      converted += to_string((ch - 'a') + 1);

    int result = 0;

    for (int i = 0; i < k; i++)
    {
      result = 0;

      for (char ch : converted)
        result += ch - '0';

      converted = to_string(result);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "leetcode";
  int k = 2;

  cout << sol.getLucky(s, k);

  return 0;
}