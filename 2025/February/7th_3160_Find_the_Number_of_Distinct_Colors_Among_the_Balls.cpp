#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> queryResults(int limit, vector<vector<int>> &queries)
  {
    unordered_map<int, int> ballMap, colorMap;

    vector<int> result;

    for (auto query : queries)
    {
      int ball = query[0];
      int color = query[1];

      if (ballMap.count(ball))
      {
        int prevColor = ballMap[ball];

        colorMap[prevColor]--;

        if (colorMap[prevColor] == 0)
          colorMap.erase(prevColor);
      }

      colorMap[color]++;
      ballMap[ball] = color;

      result.push_back(colorMap.size());
    }

    return result;
  }
};

int main()
{
  Solution sol;

  int limit = 4;
  vector<vector<int>> queries = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};

  auto ans = sol.queryResults(limit, queries);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  return 0;
}