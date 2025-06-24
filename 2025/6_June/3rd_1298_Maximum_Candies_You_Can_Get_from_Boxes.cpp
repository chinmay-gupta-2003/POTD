#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys,
                 vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes)
  {
    int n = keys.size();
    vector<int> boxesFound(n, 0);

    for (auto it : initialBoxes)
      boxesFound[it] = 1;

    queue<int> q;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
      if (boxesFound[i] && status[i])
      {
        q.push(i);
        vis[i] = 1;
      }
    }

    int result = 0;

    while (!q.empty())
    {
      int front = q.front();
      q.pop();

      result += candies[front];

      for (auto it : containedBoxes[front])
        boxesFound[it] = 1;

      for (auto it : keys[front])
        status[it] = 1;

      for (int i = 0; i < n; i++)
      {
        if (boxesFound[i] && status[i] && !vis[i])
        {
          q.push(i);
          vis[i] = 1;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int>
      status = {1, 0, 1, 0},
      candies = {7, 5, 4, 100},
      initialBoxes = {0};

  vector<vector<int>> keys = {{}, {}, {1}, {}},
                      containedBoxes = {{1, 2}, {3}, {}, {}};

  cout << sol.maxCandies(status, candies, keys, containedBoxes, initialBoxes);

  return 0;
}