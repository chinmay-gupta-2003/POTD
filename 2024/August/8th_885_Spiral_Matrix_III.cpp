#include <bits/stdc++.h>
using namespace std;

class Solution
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

int main()
{
  Solution sol;
  int rows = 5, cols = 6, rStart = 1, cStart = 4;

  auto ans = sol.spiralMatrixIII(rows, cols, rStart, cStart);

  for (auto it : ans)
    cout << it[0] << " , " << it[1] << endl;

  return 0;
}