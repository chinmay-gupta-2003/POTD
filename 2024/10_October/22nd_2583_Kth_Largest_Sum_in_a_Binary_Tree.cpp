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
  long long kthLargestLevelSum(TreeNode *root, int k)
  {
    int level = 0;
    priority_queue<long long> pq;
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
      long long size = q.size(), levelSum = 0;
      level++;

      for (int i = 0; i < size; i++)
      {
        TreeNode *parent = q.front();
        q.pop();

        levelSum += parent->val;

        if (parent->left)
          q.push(parent->left);

        if (parent->right)
          q.push(parent->right);
      }

      pq.push(levelSum);
    }

    if (level < k)
      return -1;

    k = k - 1;

    while (k--)
      pq.pop();

    return pq.top();
  }
};

int main()
{
  return 0;
}