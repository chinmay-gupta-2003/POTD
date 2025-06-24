#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int firstCompleteIndexBetter(vector<int> &arr, vector<vector<int>> &mat)
  {
    int rows = mat.size(), cols = mat[0].size();

    unordered_map<int, pair<int, int>> cooordinates;

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
        cooordinates[mat[i][j]] = {i, j};
    }

    unordered_map<string, int> rowCol;

    for (int i = 0; i < arr.size(); i++)
    {
      string rowKey = "r-" + to_string(cooordinates[arr[i]].first);
      string colKey = "c-" + to_string(cooordinates[arr[i]].second);

      rowCol[rowKey]++;
      rowCol[colKey]++;

      if (rowCol[rowKey] == cols || rowCol[colKey] == rows)
        return i;
    }

    return -1;
  }

  int firstCompleteIndexOptimal(vector<int> &arr, vector<vector<int>> &mat)
  {
    int rows = mat.size(), cols = mat[0].size();

    unordered_map<int, int> cooordinates;

    for (int i = 0; i < arr.size(); i++)
      cooordinates[arr[i]] = i;

    int result = INT_MAX;

    for (int i = 0; i < rows; i++)
    {
      int maxIndex = INT_MIN;

      for (int j = 0; j < cols; j++)
        maxIndex = max(maxIndex, cooordinates[mat[i][j]]);

      result = min(result, maxIndex);
    }

    for (int j = 0; j < cols; j++)
    {
      int maxIndex = INT_MIN;

      for (int i = 0; i < rows; i++)
        maxIndex = max(maxIndex, cooordinates[mat[i][j]]);

      result = min(result, maxIndex);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {2, 8, 7, 4, 1, 3, 5, 6, 9};
  vector<vector<int>> mat = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};

  cout << sol.firstCompleteIndexBetter(arr, mat) << endl;
  cout << sol.firstCompleteIndexOptimal(arr, mat) << endl;

  return 0;
}