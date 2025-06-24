#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val)
  {
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
};

class Solution
{
public:
  vector<int> largestValues(TreeNode *root)
  {
    queue<TreeNode *> traversal;
    vector<int> result;

    if (!root)
      return result;

    traversal.push(root);

    while (!traversal.empty())
    {
      int size = traversal.size();
      int maxi = INT_MIN;

      while (size--)
      {
        auto front = traversal.front();
        traversal.pop();

        maxi = max(maxi, front->val);

        if (front->left)
          traversal.push(front->left);

        if (front->right)
          traversal.push(front->right);
      }

      result.push_back(maxi);
    }

    return result;
  }
};

int main()
{
  return 0;
}