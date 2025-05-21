#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void setZeroesBetter(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> rowVis(m, 0), colVis(n, 0);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          rowVis[i] = 1;
          colVis[j] = 1;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (rowVis[i] || colVis[j])
          matrix[i][j] = 0;
      }
    }
  }

  void setZeroesOptimal(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();

    int zeroRow = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
      }
    }
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

  sol.setZeroesBetter(matrix);

  for (auto it : matrix)
  {
    for (auto it2 : it)
      cout << it2 << " ";

    cout << endl;
  }

  return 0;
}