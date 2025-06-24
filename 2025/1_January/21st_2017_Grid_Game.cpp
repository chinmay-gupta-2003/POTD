#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long gridGame(vector<vector<int>> &grid)
  {
    long long sumRow_1 = accumulate(grid[0].begin(), grid[0].end(), 0LL), sumRow_2 = 0;

    long long pointsRobot_2 = LONG_LONG_MAX;

    for (int i = 0; i < grid[0].size(); i++)
    {
      sumRow_1 -= grid[0][i];

      pointsRobot_2 = min(pointsRobot_2, max(sumRow_1, sumRow_2));

      sumRow_2 += grid[1][i];
    }

    return pointsRobot_2;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid = {{2, 5, 4}, {1, 5, 1}};

  cout << sol.gridGame(grid);

  return 0;
}