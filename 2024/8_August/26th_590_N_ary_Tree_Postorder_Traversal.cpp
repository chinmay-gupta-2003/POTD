#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

void solve(Node *root, vector<int> &result)
{
  if (!root)
    return;

  for (auto it : root->children)
  {
    solve(it, result);
  }

  result.push_back(root->val);
}

class Solution
{
public:
  vector<int> postorder(Node *root)
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