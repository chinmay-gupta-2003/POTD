#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    int size = original.size();

    if (m * n != size)
      return {};

    vector<vector<int>> result(m, vector<int>(n));

    for (int i = 0; i < size; i++)
    {
      int row = i / n;
      int col = i - row * n;

      result[row][col] = original[i];
    }

    return result;
  }
};

int main()
{
  Solution sol;

  int m = 2, n = 4;
  vector<int> original = {1, 2, 3, 4, 5, 6, 7, 8};

  auto ans = sol.construct2DArray(original, m, n);

  for (auto row : ans)
  {
    for (auto col : row)
      cout << col << " ";

    cout << endl;
  }

  return 0;
}