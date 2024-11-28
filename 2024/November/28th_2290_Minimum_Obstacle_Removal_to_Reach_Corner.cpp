#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumObstacles(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size();

    int drow[] = {-1, 0, 0, 1};
    int dcol[] = {0, -1, 1, 0};

    vector<vector<int>>
        cost(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    cost[0][0] = 0;
    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();

      int currCost = top.first;
      int row = top.second.first;
      int col = top.second.second;

      for (int k = 0; k < 4; k++)
      {
        int newRow = row + drow[k];
        int newCol = col + dcol[k];

        if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n)
        {
          int edgeCost = grid[newRow][newCol];

          if (currCost + edgeCost < cost[newRow][newCol])
          {
            cost[newRow][newCol] = currCost + edgeCost;
            pq.push({cost[newRow][newCol], {newRow, newCol}});
          }
        }
      }
    }

    return cost[m - 1][n - 1];
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};

  cout << sol.minimumObstacles(grid);

  return 0;
}