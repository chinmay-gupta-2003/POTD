#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    int cntNeg = 0, minVal = INT_MAX;
    long long sum = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
      for (int j = 0; j < matrix[0].size(); j++)
      {
        if (matrix[i][j] < 0)
          cntNeg++;

        sum += abs(matrix[i][j]);

        minVal = min(minVal, abs(matrix[i][j]));
      }
    }

    if (cntNeg % 2)
      return sum - 2 * minVal;

    return sum;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> matrix = {{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};

  cout << sol.maxMatrixSum(matrix);

  return 0;
}