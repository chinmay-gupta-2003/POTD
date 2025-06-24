#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minLengthBetter(string s)
  {
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
      char ch = s[i];

      if (st.empty())
        st.push(ch);
      else if (ch == 'B' && st.top() == 'A')
        st.pop();
      else if (ch == 'D' && st.top() == 'C')
        st.pop();
      else
        st.push(ch);
    }

    return st.size();
  }

  int minLengthOptimal(string s)
  {
    int i = 0, j = 1;

    while (j < s.length())
    {
      if (i < 0)
        s[++i] = s[j];
      else if ((s[j] == 'B' && s[i] == 'A') || (s[j] == 'D' && s[i] == 'C'))
        i--;
      else
        s[++i] = s[j];

      j++;
    }

    return i + 1;
  }
};

int main()
{
  Solution sol;
  string s = "ABFCACDB";

  cout << sol.minLengthBetter(s) << endl;
  cout << sol.minLengthOptimal(s) << endl;

  return 0;
}