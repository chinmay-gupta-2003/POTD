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
  int treeHeight(TreeNode *root, int skip)
  {
    if (!root)
      return 0;

    if (root->val == skip)
      return -1;

    int lh = 0, rh = 0;

    if (root->left)
      lh = 1 + treeHeight(root->left, skip);

    if (root->right)
      rh = 1 + treeHeight(root->right, skip);

    return max(lh, rh);
  }

  vector<int> treeQueriesBetter(TreeNode *root, vector<int> &queries)
  {
    vector<int> height;

    for (auto it : queries)
    {
      int h = treeHeight(root, it);

      height.push_back(h);
    }

    return height;
  }

  int populateTree(TreeNode *root, int l, vector<int> &height,
                   vector<int> &level, vector<pair<int, int>> &twoMaxHeight)
  {
    if (!root)
      return 0;

    level[root->val] = l;

    int lh, rh;

    lh = 1 + populateTree(root->left, l + 1, height, level, twoMaxHeight);
    rh = 1 + populateTree(root->right, l + 1, height, level, twoMaxHeight);

    int h = max(lh, rh);

    height[root->val] = h;

    int maxh = twoMaxHeight[l].first;
    int smaxh = twoMaxHeight[l].second;

    if (h > maxh)
    {
      smaxh = maxh;
      maxh = h;
    }
    else if (h > smaxh)
      smaxh = h;

    twoMaxHeight[l] = {maxh, smaxh};

    return h;
  }

  vector<int> treeQueriesOptimal(TreeNode *root, vector<int> &queries)
  {
    int maxn = 1e5 + 2;

    vector<int> height(maxn, 0), level(maxn, -1), ans;
    vector<pair<int, int>> twoMaxHeight(maxn, {0, 0});

    populateTree(root, 0, height, level, twoMaxHeight);

    for (auto it : queries)
    {
      int h = height[it];
      int l = level[it];

      int maxLevelHeight = twoMaxHeight[l].first;
      int secondMaxLevelHeight = twoMaxHeight[l].second;

      if (h == maxLevelHeight)
        ans.push_back(l + secondMaxLevelHeight - 1);
      else
        ans.push_back(l + maxLevelHeight - 1);
    }

    return ans;
  }
};

int main()
{
  return 0;
}