#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string resultingStringBrute(string s)
  {
    int n = s.length();
    stack<char> st;

    for (int i = 0; i < n; i++)
    {
      if (!st.empty())
      {
        char &top = st.top();

        if ((s[i] == 'z' && top == 'a') || (s[i] == 'a' && top == 'z') || (abs(s[i] - top) == 1))
          st.pop();
        else
          st.push(s[i]);
      }
      else
        st.push(s[i]);
    }

    string result = "";

    while (!st.empty())
    {
      result.push_back(st.top());
      st.pop();
    }

    reverse(result.begin(), result.end());

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "abazdbaza";

  cout << sol.resultingStringBrute(s) << endl;

  return 0;
}