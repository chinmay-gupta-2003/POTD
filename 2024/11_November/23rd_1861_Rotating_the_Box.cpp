#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
  {
    int m = box.size(), n = box[0].size();

    vector<vector<char>> result(n, vector<char>(m, '.'));

    for (int i = 0; i < m; i++)
    {
      int k = n - 1;

      for (int j = n - 1; j >= 0; j--)
      {
        if (box[i][j] == '*')
        {
          result[j][m - 1 - i] = '*';
          k = j - 1;
        }
        else if (box[i][j] == '#')
          result[k--][m - 1 - i] = '#';
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;

  vector<vector<char>> martix = {{'#', '#', '*', '.', '*', '.'},
                                 {'#', '#', '#', '*', '.', '.'},
                                 {'#', '#', '#', '.', '#', '.'}};

  auto result = sol.rotateTheBox(martix);

  for (auto it : result)
  {
    for (auto ele : it)
      cout << ele << " ";

    cout << endl;
  }

  return 0;
}