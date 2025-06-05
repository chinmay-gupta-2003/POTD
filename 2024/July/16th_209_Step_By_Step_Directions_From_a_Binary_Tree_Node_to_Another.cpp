#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

class Solution
{
public:
  bool dfs(int node, int parent,
           unordered_map<int, vector<pair<int, char>>> &adj, int dest,
           string &path)
  {
    if (node == dest)
      return true;

    for (auto adjNode : adj[node])
    {
      if (adjNode.first != parent)
      {
        path.push_back(adjNode.second);

        if (dfs(adjNode.first, node, adj, dest, path))
          return true;

        path.pop_back();
      }
    }

    return false;
  }

  string getDirections(TreeNode *root, int startValue, int destValue)
  {
    unordered_map<int, vector<pair<int, char>>> adj;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *front = q.front();
      q.pop();

      if (front->left)
      {
        adj[front->val].push_back({front->left->val, 'L'});
        adj[front->left->val].push_back({front->val, 'U'});

        q.push(front->left);
      }

      if (front->right)
      {
        adj[front->val].push_back({front->right->val, 'R'});
        adj[front->right->val].push_back({front->val, 'U'});

        q.push(front->right);
      }
    }

    string path = "";

    dfs(startValue, -1, adj, destValue, path);

    return path;
  }
};

int main()
{
  return 0;
}