#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isPair(TreeNode *start, TreeNode *end, int distance,
              unordered_map<TreeNode *, vector<TreeNode *>> &adjList)
  {
    queue<pair<TreeNode *, int>> q;
    unordered_map<TreeNode *, int> vis;

    q.push({start, 0});
    vis[start] = 1;

    while (!q.empty())
    {
      auto front = q.front();
      q.pop();

      TreeNode *parent = front.first;
      int currDist = front.second;

      if (currDist > distance)
        return false;

      if (parent == end && currDist <= distance)
        return true;

      for (TreeNode *adjNode : adjList[parent])
      {
        if (!vis[adjNode])
          q.push({adjNode, currDist + 1});
      }
    }

    return false;
  }

  int countPairsBrute(TreeNode *root, int distance)
  {
    unordered_map<TreeNode *, vector<TreeNode *>> adjList;

    queue<TreeNode *> q;
    q.push(root);

    vector<TreeNode *> leafNodes;

    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();

      if (front->left)
      {
        adjList[front].push_back(front->left);
        adjList[front->left].push_back(front);

        q.push(front->left);
      }

      if (front->right)
      {
        adjList[front].push_back(front->right);
        adjList[front->right].push_back(front);

        q.push(front->right);
      }

      if (!front->left && !front->right)
        leafNodes.push_back(front);
    }

    int n = leafNodes.size(), result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (isPair(leafNodes[i], leafNodes[j], distance, adjList))
          result++;
      }
    }

    return result;
  }

  int numPairs(TreeNode *start, unordered_set<TreeNode *> &leafNodes, int distance,
               unordered_map<TreeNode *, vector<TreeNode *>> &adjList)
  {
    queue<TreeNode *> q;
    unordered_map<TreeNode *, int> vis;

    int level = 0, pairsCount = 0;

    q.push(start);
    vis[start] = 1;

    for (int level = 0; level <= distance; level++)
    {
      int n = q.size();

      for (int i = 0; i < n; i++)
      {
        TreeNode *front = q.front();
        q.pop();

        if (leafNodes.count(front) && front != start)
          pairsCount++;
        else
        {
          for (TreeNode *adjNode : adjList[front])
          {
            if (!vis[adjNode])
            {
              q.push(adjNode);
              vis[adjNode] = 1;
            };
          }
        }
      }
    }

    return pairsCount;
  }

  int countPairsBetter(TreeNode *root, int distance)
  {
    unordered_map<TreeNode *, vector<TreeNode *>> adjList;

    queue<TreeNode *> q;
    q.push(root);

    unordered_set<TreeNode *> leafNodes;

    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();

      if (front->left)
      {
        adjList[front].push_back(front->left);
        adjList[front->left].push_back(front);

        q.push(front->left);
      }

      if (front->right)
      {
        adjList[front].push_back(front->right);
        adjList[front->right].push_back(front);

        q.push(front->right);
      }

      if (!front->left && !front->right)
        leafNodes.insert(front);
    }

    int result = 0;

    for (TreeNode *start : leafNodes)
      result += numPairs(start, leafNodes, distance, adjList);

    return result / 2;
  }

  vector<int> solve(TreeNode *root, int distance, int &result)
  {
    if (!root)
      return {0};

    if (!root->left && !root->right)
      return {1};

    vector<int> leftDist = solve(root->left, distance, result);
    vector<int> rightDist = solve(root->right, distance, result);

    vector<int> dist;

    for (int left : leftDist)
    {
      for (int right : rightDist)
      {
        if ((left && right) && left + right <= distance)
          result++;
      }
    }

    for (int left : leftDist)
    {
      if (left && left + 1 <= distance)
        dist.push_back(left + 1);
    }

    for (int right : rightDist)
    {
      if (right && right + 1 <= distance)
        dist.push_back(right + 1);
    }

    return dist;
  }

  int countPairsOptimal(TreeNode *root, int distance)
  {
    int result = 0;

    solve(root, distance, result);

    return result;
  }
};

int main()
{
  return 0;
}