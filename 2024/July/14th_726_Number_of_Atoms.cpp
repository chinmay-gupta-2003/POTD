#include <bits/stdc++.h>
using namespace std;

class Solution
{
  typedef map<string, int> MAP;

public:
  string countOfAtoms(string formula)
  {
    int i = 0, n = formula.size();

    stack<MAP> st;
    st.push(MAP());

    while (i < n)
    {
      if (formula[i] == '(')
      {
        st.push(MAP());

        i++;
      }
      else if (formula[i] == ')')
      {
        MAP currMap = st.top();
        st.pop();

        i++;

        string currNumber = "";

        while (i < n && isdigit(formula[i]))
        {
          currNumber.push_back(formula[i]);

          i++;
        }

        if (currNumber.length() > 0)
        {
          int multiplier = stoi(currNumber);

          for (auto &it : currMap)
            currMap[it.first] *= multiplier;
        }

        for (auto &it : currMap)
          st.top()[it.first] += it.second;
      }
      else
      {
        string currElement = "";

        currElement += formula[i];
        i++;

        while (i < n && islower(formula[i]))
        {
          currElement.push_back(formula[i]);

          i++;
        }

        string currNumber = "";

        while (i < n && isdigit(formula[i]))
        {
          currNumber.push_back(formula[i]);

          i++;
        }

        int number = 1;

        if (currNumber.length() > 0)
          number = stoi(currNumber);

        st.top()[currElement] += number;
      }
    }

    string result = "";

    for (auto &it : st.top())
    {
      result.append(it.first);

      if (it.second > 1)
        result.append(to_string(it.second));
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string formula = "Mg(OH)2";

  cout << sol.countOfAtoms(formula) << endl;

  return 0;
}