#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumGain(string s, int x, int y)
  {
    stack<char> st;
    int result = 0;

    char ch1 = x > y ? 'b' : 'a';
    char ch2 = x > y ? 'a' : 'b';

    if (x < y)
      swap(x, y);

    for (char &ch : s)
    {
      if (ch == ch1 && !st.empty() && st.top() == ch2)
      {
        st.pop();

        result += x;
      }
      else
        st.push(ch);
    }

    string stringLeft = "";

    while (!st.empty())
    {
      stringLeft.push_back(st.top());

      st.pop();
    }

    reverse(stringLeft.begin(), stringLeft.end());

    for (char &ch : stringLeft)
    {
      if (ch == ch2 && !st.empty() && st.top() == ch1)
      {
        st.pop();

        result += y;
      }
      else
        st.push(ch);
    }

    return result;
  }

  int maximumGainOptimal(string s, int x, int y)
  {
    stack<char> st;
    int result = 0;

    string maxStr = x > y ? "ab" : "ba";
    string minStr = x > y ? "ba" : "ab";

    if (x < y)
      swap(x, y);

    int i = 0;

    for (int j = 0; j < s.length(); j++)
    {
      s[i] = s[j];
      i++;

      if (i > 1 && s[i - 1] == maxStr[1] && s[i - 2] == maxStr[0])
      {
        i -= 2;
        result += x;
      }
    }

    s.erase(s.begin() + i, s.end());

    for (int i = 0, j = 0; j < s.length(); j++)
    {
      s[i] = s[j];
      i++;

      if (i > 1 && s[i - 1] == minStr[1] && s[i - 2] == minStr[0])
      {
        i -= 2;
        result += y;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "cdbcbbaaabab";
  int x = 4, y = 5;

  cout << sol.maximumGain(s, x, y) << endl;
  cout << sol.maximumGainOptimal(s, x, y) << endl;

  return 0;
}