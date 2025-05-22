#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;

  Node(int val)
  {
    this->val = val;
    next = nullptr;
  }
};

class Solution
{
public:
  int findTheWinnerBrute(int n, int k)
  {
    if (k == 1)
      return n;

    Node *head = new Node(1);
    Node *curr = head;

    for (int player = 2; player <= n; player++)
    {
      Node *temp = new Node(player);

      curr->next = temp;
      curr = curr->next;
    }

    curr->next = head;

    curr = head;

    while (curr->next != curr)
    {
      for (int i = 1; i < k - 1; i++)
        curr = curr->next;

      curr->next = curr->next->next;

      curr = curr->next;
    }

    return curr->val;
  }

  int solve(int n, int k)
  {
    if (n == 1)
      return 0;

    int index = solve(n - 1, k);

    index = (index + k) % n;

    return index;
  }

  int findTheWinnerOptimal(int n, int k)
  {
    return solve(n, k) + 1;
  }
};

int main()
{
  Solution sol;
  int n = 6, k = 1;

  cout << sol.findTheWinnerBrute(n, k) << endl;
  cout << sol.findTheWinnerOptimal(n, k) << endl;

  return 0;
}