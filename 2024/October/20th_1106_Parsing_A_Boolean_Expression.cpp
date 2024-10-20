#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool helper(vector<bool> &s, char c)
  {
    bool val;

    if (c == '&')
    {
      val = true;

      for (auto it : s)
        val &= it;
    }

    else if (c == '|')
    {
      val = false;

      for (auto it : s)
        val |= it;
    }

    else
      val = !s[0];

    return val;
  }

  bool parseBoolExpr(string expression)
  {
    stack<char> st;

    for (auto c : expression)
    {
      if (c == ')')
      {
        vector<bool> s;

        while (st.top() != '(')
        {
          char top = st.top();
          st.pop();

          s.push_back(top == 't');
        }

        st.pop();

        char f = st.top();
        st.pop();

        char eval = helper(s, f) ? 't' : 'f';

        st.push(eval);
      }

      else if (c != ',')
        st.push(c);
    }

    return st.top() == 't';
  }
};

int main()
{
  Solution sol;
  string s = "|(&(t,f,t),t)";

  cout << sol.parseBoolExpr(s) << endl;

  return 0;
}