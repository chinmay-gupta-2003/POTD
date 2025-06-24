#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int bfs(int start, vector<int> &vis, vector<vector<int>> &adj)
  {
    queue<pair<int, int>> q;

    q.push({start, 0});
    vis[start] = 1;

    int maxDist = 0;

    while (!q.empty())
    {
      auto front = q.front();
      q.pop();

      int node = front.first;
      int currDist = front.second;

      maxDist = currDist;

      for (int adjNode : adj[node])
      {
        if (!vis[adjNode])
        {
          q.push({adjNode, currDist + 1});
          vis[adjNode] = 1;
        }
      }
    }

    return maxDist;
  }

  int maximumInvitations(vector<int> &favorite)
  {
    int n = favorite.size();

    vector<vector<int>> revAdj(n);

    for (int i = 0; i < n; i++)
    {
      int u = i;
      int v = favorite[i];

      revAdj[v].push_back(u);
    }

    int maxCycleLength = 0;
    int cycleTwoSummation = 0;

    vector<int> visted(n, 0);

    for (int i = 0; i < n; i++)
    {
      int currNode = i;
      int currLength = 0;

      unordered_map<int, int> lengthMap;

      while (!visted[currNode])
      {
        visted[currNode] = 1;
        lengthMap[currNode] = currLength;

        int nextNode = favorite[currNode];
        currLength++;

        if (lengthMap.count(nextNode))
        {
          int cycleLength = currLength - lengthMap[nextNode];

          maxCycleLength = max(maxCycleLength, cycleLength);

          if (cycleLength == 2)
          {
            vector<int> vis(n, 0);

            vis[currNode] = 1;
            vis[nextNode] = 1;

            cycleTwoSummation += 2 + bfs(currNode, vis, revAdj) + bfs(nextNode, vis, revAdj);
          }

          break;
        }

        currNode = nextNode;
      }
    }

    return max(cycleTwoSummation, maxCycleLength);
  }
};

int main()
{
  Solution sol;
  vector<int> favourite = {3, 0, 1, 4, 1};

  cout << sol.maximumInvitations(favourite);

  return 0;
}