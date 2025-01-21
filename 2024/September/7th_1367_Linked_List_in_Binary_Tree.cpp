#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  ListNode(int val)
  {
    this->val = val;
    this->next = nullptr;
  }
};

class TreeNode
{
public:
  int val;
  TreeNode *right, *left;

  TreeNode(int val)
  {
    this->val = val;
    this->right = nullptr;
    this->left = nullptr;
  }
};

class Solution
{
public:
  bool checkNode(ListNode *head, TreeNode *root)
  {
    if (!head)
      return true;

    if (!root)
      return false;

    if (head->val != root->val)
      return false;

    bool leftNodeEqual, rightNodeEqual;

    leftNodeEqual = checkNode(head->next, root->left);
    rightNodeEqual = checkNode(head->next, root->right);

    return leftNodeEqual || rightNodeEqual;
  }

  bool isSubPath(ListNode *head, TreeNode *root)
  {
    if (!root)
      return false;

    bool check = checkNode(head, root);
    bool leftNodeEqual = isSubPath(head, root->left);
    bool rightNodeEqual = isSubPath(head, root->right);

    return check || leftNodeEqual || rightNodeEqual;
  }
};

int main()
{
  return 0;
}