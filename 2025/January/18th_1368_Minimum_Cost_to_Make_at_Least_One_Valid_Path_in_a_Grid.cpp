#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, pair<int, int>> P;

  int minCost(vector<vector<int>> &grid)
  {
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

    pq.push({0, {0, 0}});
    dist[0][0] = 0;

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();

      int cost = top.first;
      int row = top.second.first;
      int col = top.second.second;

      for (int i = 1; i <= 4; i++)
      {
        int newRow = row + directions[i - 1].first;
        int newCol = col + directions[i - 1].second;

        if (newRow >= 0 && newCol >= 0 && newRow < rows &&
            newCol < cols)
        {
          int newCost = (i == grid[row][col]) ? cost : cost + 1;

          if (newCost < dist[newRow][newCol])
          {
            pq.push({newCost, {newRow, newCol}});
            dist[newRow][newCol] = newCost;
          }
        }
      }
    }

    return dist[rows - 1][cols - 1];
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}};

  cout << sol.minCost(grid);

  return 0;
}