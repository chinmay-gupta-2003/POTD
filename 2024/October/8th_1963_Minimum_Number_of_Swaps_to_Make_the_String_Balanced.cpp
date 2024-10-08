#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minSwapsBrute(string s)
  {
    stack<char> st;

    for (auto it : s)
    {
      if (it == '[')
        st.push(it);
      else if (!st.empty())
        st.pop();
    }

    return (st.size() + 1) / 2;
  }

  int minSwapsOptimal(string s)
  {
    int size = 0;

    for (auto it : s)
    {
      if (it == '[')
        size++;
      else if (size > 0)
        size--;
    }

    return (size + 1) / 2;
  }
};

int main()
{
  Solution sol;
  string s = "[]";

  cout << sol.minSwapsBrute(s) << endl;
  cout << sol.minSwapsOptimal(s) << endl;

  return 0;
}