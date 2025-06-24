#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int solve(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<int>> &vis, int &flag)
  {
    vis[i][j] = 1;

    if (!grid1[i][j])
      flag = 1;

    vector<vector<int>> coords = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int k = 0; k < 4; k++)
    {
      int nrow = i + coords[k][0];
      int ncol = j + coords[k][1];

      if (nrow >= 0 && nrow < grid2.size() && ncol >= 0 && ncol < grid2[0].size() && !vis[nrow][ncol] && grid2[nrow][ncol])
        solve(nrow, ncol, grid1, grid2, vis, flag);
    }

    return flag;
  }

public:
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
  {
    int m = grid1.size(), n = grid1[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));

    int result = 0;

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int flag = 0;

        if (!vis[i][j] && grid2[i][j] && solve(i, j, grid1, grid2, vis, flag) == 0)
          result++;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> grid1 = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 1}},
                      grid2 = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 1, 0, 1}, {1, 0, 0, 1}};

  cout << sol.countSubIslands(grid1, grid2);

  return 0;
}