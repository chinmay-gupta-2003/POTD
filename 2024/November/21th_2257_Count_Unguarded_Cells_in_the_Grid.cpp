#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void markCells(int row, int col, vector<vector<int>> &matrix)
  {
    for (int i = row - 1; i >= 0; i--)
    {
      if (matrix[i][col] == 1 || matrix[i][col] == 2)
        break;

      matrix[i][col] = -1;
    }

    for (int i = row + 1; i < matrix.size(); i++)
    {
      if (matrix[i][col] == 1 || matrix[i][col] == 2)
        break;

      matrix[i][col] = -1;
    }

    for (int j = col - 1; j >= 0; j--)
    {
      if (matrix[row][j] == 1 || matrix[row][j] == 2)
        break;

      matrix[row][j] = -1;
    }

    for (int j = col + 1; j < matrix[0].size(); j++)
    {
      if (matrix[row][j] == 1 || matrix[row][j] == 2)
        break;

      matrix[row][j] = -1;
    }
  }

  int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls)
  {
    vector<vector<int>> matrix(m, vector<int>(n, 0));

    for (int i = 0; i < guards.size(); i++)
    {
      int row = guards[i][0];
      int col = guards[i][1];

      matrix[row][col] = 1;
    }

    for (int i = 0; i < walls.size(); i++)
    {
      int row = walls[i][0];
      int col = walls[i][1];

      matrix[row][col] = 2;
    }

    for (int i = 0; i < guards.size(); i++)
    {
      int row = guards[i][0];
      int col = guards[i][1];

      markCells(row, col, matrix);
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (!matrix[i][j])
          count++;
      }
    }

    return count;
  }
};

int main()
{
  Solution sol;

  int m = 4, n = 6;
  vector<vector<int>> guards = {{0, 0}, {1, 1}, {2, 3}}, walls = {{0, 1}, {2, 2}, {1, 4}};

  cout << sol.countUnguarded(m, n, guards, walls);

  return 0;
}