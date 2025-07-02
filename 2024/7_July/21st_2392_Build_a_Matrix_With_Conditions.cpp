#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool topoSort(int k, vector<vector<int>> &adj, unordered_map<int, int> &indexMap)
  {
    vector<int> indeg(k + 1, 0);

    for (int i = 1; i <= k; i++)
    {
      for (int ngbr : adj[i])
        indeg[ngbr]++;
    }

    queue<int> q;

    for (int i = 1; i <= k; i++)
    {
      if (indeg[i] == 0)
        q.push(i);
    }

    int idx = 0, check = 0;

    while (!q.empty())
    {
      int front = q.front();
      q.pop();

      check++;

      indexMap[front] = idx++;

      for (int ngbr : adj[front])
      {
        indeg[ngbr]--;

        if (indeg[ngbr] == 0)
          q.push(ngbr);
      }
    }

    if (check != k)
      return false;

    return true;
  }

  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
  {
    vector<vector<int>> rowAdj(k + 1), colAdj(k + 1);

    for (auto it : rowConditions)
    {
      int u = it[0], v = it[1];

      rowAdj[u].push_back(v);
    }

    for (auto it : colConditions)
    {
      int u = it[0], v = it[1];

      colAdj[u].push_back(v);
    }

    unordered_map<int, int> rowIndexMap, colIndexMap;

    if (!topoSort(k, rowAdj, rowIndexMap))
      return {};

    if (!topoSort(k, colAdj, colIndexMap))
      return {};

    vector<vector<int>> result(k, vector<int>(k, 0));

    for (int i = 1; i <= k; i++)
    {
      int row = rowIndexMap[i];
      int col = colIndexMap[i];

      result[row][col] = i;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> rowConditions = {{1, 2}, {3, 2}}, colConditions = {{2, 1}, {3, 2}};
  int k = 3;

  auto ans = sol.buildMatrix(k, rowConditions, colConditions);

  for (auto rows : ans)
  {
    for (auto col : rows)
      cout << col << " ";

    cout << endl;
  }

  return 0;
}