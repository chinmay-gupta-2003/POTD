#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string reverseParenthesesBrute(string s)
  {
    vector<int> parenthesisIndex;
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
      char &ch = s[i];

      if (ch == '(')
        parenthesisIndex.push_back(result.length());
      else if (ch == ')')
      {
        reverse(result.begin() + parenthesisIndex.back(), result.end());

        parenthesisIndex.pop_back();
      }
      else
        result += ch;
    }

    return result;
  }

  string reverseParenthesesOptimal(string s)
  {
    int n = s.length();

    stack<int> st;
    unordered_map<int, int> parenthesisMapping;

    for (int j = 0; j < n; j++)
    {
      if (s[j] == '(')
        st.push(j);
      else if (s[j] == ')')
      {
        int top = st.top();
        st.pop();

        parenthesisMapping[top] = j;
        parenthesisMapping[j] = top;
      }
    }

    int i = 0, direction = 1;
    string result = "";

    while (i < n)
    {
      char &ch = s[i];

      if (ch == '(' || ch == ')')
      {
        direction = !direction;
        i = parenthesisMapping[i];
      }
      else
        result += ch;

      if (direction)
        i++;
      else
        i--;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "ta()usw((((a))))";

  cout << sol.reverseParenthesesBrute(s) << endl;
  cout << sol.reverseParenthesesOptimal(s) << endl;

  return 0;
}