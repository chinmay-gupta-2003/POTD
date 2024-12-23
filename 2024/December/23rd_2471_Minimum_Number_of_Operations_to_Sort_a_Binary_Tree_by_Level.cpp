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
  int minimumOperations(TreeNode *root)
  {
    int result = 0;
    queue<TreeNode *> traversal;

    traversal.push(root);

    while (!traversal.empty())
    {
      int size = traversal.size();

      vector<int> level;
      unordered_map<int, int> indexMap;

      for (int i = 0; i < size; i++)
      {
        auto front = traversal.front();
        traversal.pop();

        level.push_back(front->val);
        indexMap[front->val] = i;

        if (front->left)
          traversal.push(front->left);

        if (front->right)
          traversal.push(front->right);
      }

      vector<int> sortedLevel = level;
      sort(sortedLevel.begin(), sortedLevel.end());

      for (int i = 0; i < level.size(); i++)
      {
        int num = level[i], correctNum = sortedLevel[i],
            correctIndex = indexMap[correctNum];

        if (num != correctNum)
        {
          swap(level[i], level[correctIndex]);

          indexMap[correctNum] = i;
          indexMap[num] = correctIndex;

          result++;
        }
      }
    }

    return result;
  }
};

int main()
{
  return 0;
}