#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
  vector<int> parent, size;

  DisjointSet(int n)
  {
    parent.resize(n);
    size.resize(n);

    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int FindParent(int x)
  {
    if (parent[x] == x)
      return x;

    return parent[x] = FindParent(parent[x]);
  }

  void UnionBySize(int u, int v)
  {
    int parent_u = FindParent(u), parent_v = FindParent(v);

    if (parent_u == parent_v)
      return;

    if (size[parent_u] > size[parent_v])
    {
      size[parent_u] += size[parent_v];
      parent[parent_v] = parent_u;
    }
    else
    {
      size[parent_v] += size[parent_u];
      parent[parent_u] = parent_v;
    }
  }
};

class Solution
{
public:
  int removeStones(vector<vector<int>> &stones)
  {
    int rows = 0, cols = 0;

    int totalStones = 0;

    for (auto coords : stones)
    {
      totalStones++;

      rows = max(rows, coords[0]);
      cols = max(cols, coords[1]);
    }

    rows++;
    cols++;

    DisjointSet DS(rows + cols);

    for (auto coords : stones)
      DS.UnionBySize(coords[0], coords[1] + rows);

    int components = 0;

    for (int i = 0; i < rows + cols; i++)
    {
      if (DS.FindParent(i) == i && DS.size[i] > 1)
        components++;
    }

    return totalStones - components;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> stones = {{0, 0}, {1, 0}, {0, 2}, {2, 1}, {2, 2}};

  cout << sol.removeStones(stones);

  return 0;
}