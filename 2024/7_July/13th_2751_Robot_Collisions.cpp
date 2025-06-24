#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
  {
    int n = positions.size();
    map<int, int> positionMap;

    for (int i = 0; i < n; i++)
      positionMap.insert({positions[i], i});

    stack<int> st;

    for (auto it : positionMap)
    {
      int currentIndex = it.second;

      if (directions[it.second] == 'R')
        st.push(it.second);
      else
      {
        while (!st.empty() && healths[currentIndex])
        {
          int topIndex = st.top();
          st.pop();

          if (healths[currentIndex] == healths[topIndex])
          {
            healths[topIndex] = 0;
            healths[it.second] = 0;
          }
          else if (healths[currentIndex] < healths[topIndex])
          {
            healths[currentIndex] = 0;
            healths[topIndex]--;

            st.push(topIndex);
          }
          else
          {
            healths[topIndex] = 0;
            healths[currentIndex]--;
          }
        }
      }
    }

    vector<int> result;

    for (int health : healths)
    {
      if (health)
        result.push_back(health);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> positions = {3, 5, 2, 6}, healths = {10, 10, 15, 12};
  string directions = "RLRL";

  auto ans = sol.survivedRobotsHealths(positions, healths, directions);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}