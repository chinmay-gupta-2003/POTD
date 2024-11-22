#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int maxCount = 0;

    for (int i = 0; i < m; i++)
    {
      vector<int> inverted;

      for (int j = 0; j < n; j++)
      {
        inverted.push_back(!matrix[i][j]);
      }

      int count = 0;
      for (int k = 0; k < m; k++)
      {
        if (matrix[k] == matrix[i] || matrix[k] == inverted)
          count++;
      }

      maxCount = max(maxCount, count);
    }

    return maxCount;
  }

  int maxEqualRowsAfterFlipsOptimal(vector<vector<int>> &matrix)
  {
    int m = matrix.size(), n = matrix[0].size();
    int maxSame = 1;

    unordered_map<string, int> freqMap;

    for (int i = 0; i < m; i++)
    {
      int x = matrix[i][0];
      string s = "";

      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == x)
          s += "s";
        else
          s += "d";
      }

      freqMap[s]++;

      maxSame = max(maxSame, freqMap[s]);
    }

    return maxSame;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> matrix = {{0, 0, 0}, {0, 0, 1}, {1, 1, 0}};

  cout << sol.maxEqualRowsAfterFlips(matrix) << endl;
  cout << sol.maxEqualRowsAfterFlipsOptimal(matrix) << endl;

  return 0;
}