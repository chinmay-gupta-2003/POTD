#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  char findKthBitBrute(int n, int k)
  {
    string s = "0";

    for (int i = 1; i <= n; i++)
    {
      string temp = s;

      for (int j = 0; j < s.length(); j++)
      {
        if (s[j] == '0')
          s[j] = '1';
        else
          s[j] = '0';
      }

      reverse(s.begin(), s.end());

      s = temp + "1" + s;
    }

    return s[k - 1];
  }

  char findKthBitRecursive(int n, int k)
  {
    if (n == 1)
      return '0';

    int length = pow(2, n) - 1;
    int ceilValue = ceil(length / 2.0);

    if (k < ceilValue)
      return findKthBitRecursive(n - 1, k);

    else if (k == ceilValue)
      return '1';

    else
    {
      char ch = findKthBitRecursive(n - 1, length - k + 1);

      if (ch == '1')
        return '0';
      else
        return '1';
    }
  }
};

int main()
{
  Solution sol;

  cout << sol.findKthBitBrute(3, 1) << endl;
  cout << sol.findKthBitRecursive(3, 1) << endl;

  return 0;
}