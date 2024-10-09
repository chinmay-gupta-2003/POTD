#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minAddToMakeValidBetter(string s)
  {
    stack<char> st;
    int cnt = 0;

    for (auto it : s)
    {
      if (it == '(')
        st.push(it);
      else if (!st.empty())
        st.pop();
      else
        cnt++;
    }

    return cnt + st.size();
  }

  int minAddToMakeValidOptimal(string s)
  {
    int cnt = 0, size = 0;

    for (auto it : s)
    {
      if (it == '(')
        size++;
      else if (size > 0)
        size--;
      else
        cnt++;
    }

    return cnt + size;
  }
};

int main()
{
  Solution sol;
  string s = "())(";

  cout << sol.minAddToMakeValidBetter(s) << endl;
  cout << sol.minAddToMakeValidOptimal(s) << endl;

  return 0;
}