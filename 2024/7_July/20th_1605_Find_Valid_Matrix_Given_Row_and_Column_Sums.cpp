#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum)
  {
    int m = rowSum.size(), n = colSum.size();

    vector<vector<int>> result(m, vector<int>(n, 0));

    int i = 0, j = 0;

    while (i < m && j < n)
    {
      result[i][j] = min(rowSum[i], colSum[j]);

      rowSum[i] -= result[i][j];
      colSum[j] -= result[i][j];

      if (rowSum[i] == 0)
        i++;

      if (colSum[j] == 0)
        j++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> rowSum = {5, 7, 10}, colSum = {8, 6, 8};

  auto ans = sol.restoreMatrix(rowSum, colSum);

  for (auto row : ans)
  {
    for (auto col : row)
      cout << col << " ";

    cout << endl;
  }

  return 0;
}