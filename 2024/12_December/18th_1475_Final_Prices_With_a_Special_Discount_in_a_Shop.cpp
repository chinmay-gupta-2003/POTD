#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> finalPricesBrute(vector<int> &prices)
  {
    int n = prices.size();

    vector<int> result = prices;

    for (int i = 0; i < n; i++)
    {
      int nextSmaller = INT_MAX;

      for (int j = i + 1; j < n; j++)
      {
        if (prices[j] <= prices[i])
        {
          nextSmaller = prices[j];
          break;
        }
      }

      if (nextSmaller <= prices[i])
        result[i] = prices[i] - nextSmaller;
    }

    return result;
  }

  vector<int> finalPricesOptimal(vector<int> &prices)
  {
    int n = prices.size();

    vector<int> result = prices;
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && prices[i] < st.top())
        st.pop();

      if (!st.empty())
        result[i] -= st.top();

      st.push(prices[i]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> prices = {10, 1, 1, 6};

  auto ans = sol.finalPricesBrute(prices);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.finalPricesOptimal(prices);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}