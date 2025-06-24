#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, pair<int, int>> P;

  int trapRainWater(vector<vector<int>> &heightMap)
  {
    int rows = heightMap.size(), cols = heightMap[0].size();

    if (rows < 3 || cols < 3)
      return 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> vis(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
      pq.push({heightMap[i][0], {i, 0}});
      vis[i][0] = 1;

      pq.push({heightMap[i][cols - 1], {i, cols - 1}});
      vis[i][cols - 1] = 1;
    }

    for (int j = 0; j < cols; j++)
    {
      pq.push({heightMap[0][j], {0, j}});
      vis[0][j] = 1;

      pq.push({heightMap[rows - 1][j], {rows - 1, j}});
      vis[rows - 1][j] = 1;
    }

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int result = 0;

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();

      int height = top.first;
      int row = top.second.first;
      int col = top.second.second;

      for (int i = 0; i < 4; i++)
      {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !vis[newRow][newCol])
        {
          pq.push({max(height, heightMap[newRow][newCol]), {newRow, newCol}});
          vis[newRow][newCol] = 1;

          result += max(0, height - heightMap[newRow][newCol]);
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> heightMap = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};

  cout << sol.trapRainWater(heightMap);

  return 0;
}