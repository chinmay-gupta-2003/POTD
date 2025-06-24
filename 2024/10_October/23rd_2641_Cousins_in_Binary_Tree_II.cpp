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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
  TreeNode *replaceValueInTreeBrute(TreeNode *root)
  {
    vector<int> levelSum;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
      int size = q.size();
      int sum = 0;

      for (int i = 0; i < size; i++)
      {
        auto front = q.front();
        q.pop();

        sum += front->val;

        if (front->left)
          q.push(front->left);

        if (front->right)
          q.push(front->right);
      }

      levelSum.push_back(sum);
    }

    q.push(root);
    root->val = 0;
    int i = 1;

    while (!q.empty())
    {
      int size = q.size();

      for (int j = 0; j < size; j++)
      {
        auto front = q.front();
        q.pop();

        int sum = 0;

        if (front->left)
          sum += front->left->val;

        if (front->right)
          sum += front->right->val;

        if (front->left)
        {
          q.push(front->left);
          front->left->val = levelSum[i] - sum;
        }

        if (front->right)
        {
          q.push(front->right);
          front->right->val = levelSum[i] - sum;
        }
      }

      i++;
    }

    return root;
  }

  TreeNode *replaceValueInTreeOptimal(TreeNode *root)
  {
    queue<TreeNode *> q;
    int levelSum;

    q.push(root);
    levelSum = root->val;

    while (!q.empty())
    {
      int size = q.size();
      int nextLevelSum = 0;

      for (int i = 0; i < size; i++)
      {
        int siblingSum = 0;

        auto front = q.front();
        q.pop();

        front->val = levelSum - front->val;

        auto left = front->left;
        if (left)
        {
          siblingSum += left->val;
          q.push(left);
        }

        auto right = front->right;
        if (right)
        {
          siblingSum += right->val;
          q.push(right);
        }

        if (left)
          left->val = siblingSum;

        if (right)
          right->val = siblingSum;

        nextLevelSum += siblingSum;
      }

      levelSum = nextLevelSum;
    }

    return root;
  }
};

int main()
{
  return 0;
}