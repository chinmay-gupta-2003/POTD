#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> solve(string s)
  {
    vector<int> result;

    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '+' || s[i] == '-' || s[i] == '*')
      {
        vector<int> leftResults = solve(s.substr(0, i));
        vector<int> rightResults = solve(s.substr(i + 1));

        for (int &m : leftResults)
        {
          for (int &n : rightResults)
          {
            if (s[i] == '+')
              result.push_back(m + n);
            else if (s[i] == '-')
              result.push_back(m - n);
            else
              result.push_back(m * n);
          }
        }
      }
    }

    if (result.empty())
      result.push_back(stoi(s));

    return result;
  }

  vector<int> diffWaysToCompute(string expression)
  {
    return solve(expression);
  }
};

int main()
{
  Solution sol;
  string expression = "2*3-4*5";

  vector<int> ans = sol.diffWaysToCompute(expression);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}