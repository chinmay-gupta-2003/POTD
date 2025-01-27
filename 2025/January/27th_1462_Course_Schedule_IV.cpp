#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<bool> checkIfPrerequisiteBellmanFord(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {
    vector<vector<int>> adj(numCourses);
    vector<vector<int>> dist(numCourses, vector<int>(numCourses, 1e8));

    for (auto edge : prerequisites)
    {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);

      dist[u][v] = 1;
    }

    for (int i = 0; i < numCourses; i++)
      dist[i][i] = 0;

    for (int i = 0; i < numCourses; i++)
    {
      for (int u = 0; u < numCourses; u++)
      {
        for (int v = 0; v < numCourses; v++)
        {
          if (dist[u][i] + dist[i][v] < dist[u][v])
            dist[u][v] = dist[u][i] + dist[i][v];
        }
      }
    }

    vector<bool> result;

    for (auto query : queries)
    {
      int u = query[0];
      int v = query[1];

      if (dist[u][v] != 1e8)
        result.push_back(true);
      else
        result.push_back(false);
    }

    return result;
  }

  vector<bool> checkIfPrerequisiteTopoSort(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
  {
    vector<vector<int>> adj(numCourses);
    vector<int> indeg(numCourses, 0);

    for (auto edge : prerequisites)
    {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      indeg[v]++;
    }

    queue<int> q;
    unordered_map<int, unordered_set<int>> topoSortMap;

    for (int i = 0; i < numCourses; i++)
    {
      if (indeg[i] == 0)
      {
        q.push(i);
        topoSortMap[i] = {};
      }
    }

    while (!q.empty())
    {
      int node = q.front();
      q.pop();

      for (int adjNode : adj[node])
      {
        for (auto parentNode : topoSortMap[node])
          topoSortMap[adjNode].insert(parentNode);

        topoSortMap[adjNode].insert(node);

        indeg[adjNode]--;

        if (indeg[adjNode] == 0)
          q.push(adjNode);
      }
    }

    vector<bool> result;

    for (auto query : queries)
    {
      int u = query[0];
      int v = query[1];

      if (topoSortMap[v].find(u) != topoSortMap[v].end())
        result.push_back(true);
      else
        result.push_back(false);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  int numCourses = 3;
  vector<vector<int>> prerequisites = {{1, 2}, {1, 0}, {2, 0}};
  vector<vector<int>> queries = {{1, 0}, {1, 2}};

  auto ans = sol.checkIfPrerequisiteBellmanFord(numCourses, prerequisites, queries);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.checkIfPrerequisiteTopoSort(numCourses, prerequisites, queries);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}