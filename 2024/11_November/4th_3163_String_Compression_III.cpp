#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string compressedString(string word)
  {
    int i = 0, n = word.length();
    string comp = "";

    while (i < n)
    {
      int cnt = 0;
      char ch = word[i];

      while (i < n)
      {
        if (word[i] == ch && cnt < 9)
        {
          cnt++;
          i++;
        }
        else
          break;
      }

      comp += to_string(cnt) + ch;
    }

    return comp;
  }
};

int main()
{
  Solution sol;
  string s = "abcvvvvvvvvvvvvvdefffffffffffff";

  cout << sol.compressedString(s);

  return 0;
}