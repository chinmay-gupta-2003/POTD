#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> rowMin, colMax;

    for (int i = 0; i < m; i++)
    {
      int rowMini = INT_MAX;

      for (int j = 0; j < n; j++)
        rowMini = min(rowMini, matrix[i][j]);

      rowMin.push_back(rowMini);
    }

    for (int j = 0; j < n; j++)
    {
      int colMaxi = INT_MIN;

      for (int i = 0; i < m; i++)
        colMaxi = max(colMaxi, matrix[i][j]);

      colMax.push_back(colMaxi);
    }

    vector<int> result;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (rowMin[i] == matrix[i][j] && colMax[j] == matrix[i][j])
          result.push_back(matrix[i][j]);
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};

  auto ans = sol.luckyNumbers(matrix);

  for (auto it : ans)
    cout << it;

  return 0;
}