#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  pair<int, int> getFarthestNodeAndDistance(vector<vector<int>> &adjList,
                                            int startingNode)
  {
    queue<int> bfs;
    vector<int> visited(adjList.size(), 0);

    bfs.push(startingNode);
    visited[startingNode] = 1;

    int distance = 0, farthestNode = startingNode;

    while (!bfs.empty())
    {
      int size = bfs.size();

      for (int i = 0; i < size; i++)
      {
        int front = bfs.front();
        bfs.pop();

        for (auto it : adjList[front])
        {
          if (!visited[it])
          {
            bfs.push(it);
            visited[it] = 1;
            farthestNode = it;
          }
        }
      }

      if (!bfs.empty())
        distance++;
    }

    return {farthestNode, distance};
  }

  int getDiameter(vector<vector<int>> &edges)
  {
    int n = edges.size() + 1;
    vector<vector<int>> adjList(n);

    for (auto it : edges)
    {
      adjList[it[0]].push_back(it[1]);
      adjList[it[1]].push_back(it[0]);
    }

    int endOne = getFarthestNodeAndDistance(adjList, 0).first;

    return getFarthestNodeAndDistance(adjList, endOne).second;
  }

  int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                vector<vector<int>> &edges2)
  {
    int diameterOne = getDiameter(edges1);
    int diameterTwo = getDiameter(edges2);

    int combinedDiameter =
        (diameterOne + 1) / 2 + (diameterTwo + 1) / 2 + 1;

    return max({diameterOne, diameterTwo, combinedDiameter});
  }
};

int main()
{
  return 0;
}