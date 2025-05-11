#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left, *right;

  TreeNode()
  {
    left = nullptr;
    right = nullptr;
  }
};

class Solution
{
public:
  void solve(TreeNode *root, vector<int> &result)
  {
    if (!root)
      return;

    solve(root->left, result);
    solve(root->right, result);

    result.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> result;

    solve(root, result);

    return result;
  }
};

int main()
{
  return 0;
}