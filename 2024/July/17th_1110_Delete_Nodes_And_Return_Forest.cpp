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
  TreeNode *solve(TreeNode *root, unordered_set<int> &deleteValues,
                  vector<TreeNode *> &result)
  {

    if (root == nullptr)
      return nullptr;

    root->left = solve(root->left, deleteValues, result);
    root->right = solve(root->right, deleteValues, result);

    if (deleteValues.find(root->val) != deleteValues.end())
    {
      if (root->left)
        result.push_back(root->left);

      if (root->right)
        result.push_back(root->right);

      return nullptr;
    }

    return root;
  }

  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
  {
    unordered_set<int> deleteValues(to_delete.begin(), to_delete.end());

    vector<TreeNode *> result;

    solve(root, deleteValues, result);

    if (deleteValues.find(root->val) == deleteValues.end())
      result.push_back(root);

    return result;
  }
};

int main()
{
  return 0;
}