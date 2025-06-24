#include <bits/stdc++.h>
using namespace std;

class Solution_1
{
public:
  bool isValid(int rows, int cols, int row, int col)
  {
    return (row < rows && row >= 0 && col >= 0 && col < cols);
  }

  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
  {
    int totalCellsVisited = 0;

    vector<vector<int>> result;

    result.push_back({rStart, cStart});
    totalCellsVisited++;

    int steps = 0;

    while (totalCellsVisited < rows * cols)
    {
      steps++;

      for (int i = 1; i <= steps; i++)
      {
        cStart++;

        if (isValid(rows, cols, rStart, cStart))
        {
          totalCellsVisited++;
          result.push_back({rStart, cStart});
        }
      }

      for (int i = 1; i <= steps; i++)
      {
        rStart++;

        if (isValid(rows, cols, rStart, cStart))
        {
          totalCellsVisited++;
          result.push_back({rStart, cStart});
        }
      }

      steps++;

      for (int i = 1; i <= steps; i++)
      {
        cStart--;

        if (isValid(rows, cols, rStart, cStart))
        {
          totalCellsVisited++;
          result.push_back({rStart, cStart});
        }
      }

      for (int i = 1; i <= steps; i++)
      {
        rStart--;

        if (isValid(rows, cols, rStart, cStart))
        {
          totalCellsVisited++;
          result.push_back({rStart, cStart});
        }
      }
    }

    return result;
  }
};

class Solution_2
{
public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
  {
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int step = 0;
    int dir = 0;

    vector<vector<int>> result;

    result.push_back({rStart, cStart});

    while (result.size() < rows * cols)
    {
      if (dir == 0 || dir == 2)
        step++;

      for (int i = 0; i < step; i++)
      {
        rStart += directions[dir][0];
        cStart += directions[dir][1];

        if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols)
          result.push_back({rStart, cStart});
      }

      dir = (dir + 1) % 4;
    }

    return result;
  }
};

int main()
{
  Solution_1 sol1;
  int rows = 5, cols = 6, rStart = 1, cStart = 4;

  auto ans1 = sol1.spiralMatrixIII(rows, cols, rStart, cStart);

  for (auto it : ans1)
    cout << it[0] << " , " << it[1] << endl;

  Solution_2 sol2;

  auto ans2 = sol2.spiralMatrixIII(rows, cols, rStart, cStart);

  for (auto it : ans2)
    cout << it[0] << " , " << it[1] << endl;

  return 0;
}