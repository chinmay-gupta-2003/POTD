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
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
  {
    unordered_set<int> parents, childrens, filteredParents;
    unordered_map<int, vector<pair<int, int>>> childrenMap;

    for (auto children : descriptions)
    {
      int parent = children[0];
      int child = children[1];
      int isLeft = children[2];

      parents.insert(parent);
      filteredParents.insert(parent);
      childrens.insert(child);

      childrenMap[parent].push_back({child, isLeft});
    }

    for (int parent : parents)
    {
      if (childrens.find(parent) != childrens.end())
        filteredParents.erase(parent);
    }

    int parentValue = *filteredParents.begin();

    TreeNode *parent = new TreeNode(parentValue);

    queue<TreeNode *> q;
    q.push(parent);

    while (!q.empty())
    {
      TreeNode *top = q.front();
      q.pop();

      int nodeValue = top->val;

      for (auto children : childrenMap[nodeValue])
      {
        int childrenValue = children.first;
        bool isLeft = children.second;

        TreeNode *child = new TreeNode(childrenValue);

        if (isLeft)
          top->left = child;
        else
          top->right = child;

        q.push(child);
      }
    }

    return parent;
  }
};

int main()
{
  return 0;
}