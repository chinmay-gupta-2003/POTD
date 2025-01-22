#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, pair<int, int>> PP;
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
  {
    int m = isWater.size(), n = isWater[0].size();

    queue<PP> q;
    vector<vector<int>> result(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (isWater[i][j])
        {
          q.push({0, {i, j}});
          result[i][j] = 0;
        }
      }
    }

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
    {
      auto front = q.front();
      q.pop();

      int value = front.first;
      int r = front.second.first;
      int c = front.second.second;

      for (auto dir : directions)
      {
        int nr = r + dir[0];
        int nc = c + dir[1];

        if (nr >= 0 && nr < m && nc >= 0 && nc < n && result[nr][nc] == -1)
        {
          result[nr][nc] = value + 1;
          q.push({value + 1, {nr, nc}});
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> isWater = {{0, 1}, {0, 0}};

  auto ans = sol.highestPeak(isWater);

  for (auto row : ans)
  {
    for (auto col : row)
      cout << col << " ";

    cout << endl;
  }

  return 0;
}