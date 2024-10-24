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
    this->left = nullptr;
    this->right = nullptr;
  }
};

class Solution
{
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {
    if (!root1 && !root2)
      return true;

    if (!root1 || !root2)
      return false;

    bool flag = root1->val == root2->val;

    bool left = flipEquiv(root1->left, root2->left);
    bool flipLeft = flipEquiv(root1->left, root2->right);

    bool right = flipEquiv(root1->right, root2->right);
    bool flipRight = flipEquiv(root1->right, root2->left);

    return flag && (left || flipLeft) && (right || flipRight);
  }
};