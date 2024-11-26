#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findChampion(int n, vector<vector<int>> &edges)
  {
    vector<int> indeg(n, 0);

    for (auto it : edges)
    {
      indeg[it[1]]++;
    }

    int cnt = 0, champion = -1;

    for (int i = 0; i < n; i++)
    {
      if (indeg[i] == 0)
      {
        cnt++;
        champion = i;
      }

      if (cnt > 1)
        return -1;
    }

    return champion;
  }
};

int main()
{
  Solution sol;

  int n = 4;
  vector<vector<int>> edges = {{0, 2}, {1, 3}, {1, 2}};

  cout << sol.findChampion(n, edges);

  return 0;
}