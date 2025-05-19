#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *mergeNodes(ListNode *head)
  {
    ListNode *newPointer = head;
    ListNode *temp = head->next;

    while (temp)
    {
      int sum = 0;

      while (temp->val != 0)
      {
        sum += temp->val;
        temp = temp->next;
      }

      newPointer = newPointer->next;
      newPointer->val = sum;

      temp = temp->next;
    }

    newPointer->next = nullptr;

    return head->next;
  }
};

int main()
{
  return 0;
}