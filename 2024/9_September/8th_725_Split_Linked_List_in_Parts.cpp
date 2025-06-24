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

class Solution
{
public:
  vector<ListNode *> splitListToParts(ListNode *head, int k)
  {
    int size = 0;

    ListNode *temp = head;

    while (temp)
    {
      size++;
      temp = temp->next;
    }

    int initSize = size / k;
    int leftSize = size % k;

    vector<ListNode *> result(k, nullptr);
    int index = 0;

    temp = head;

    while (temp)
    {
      result[index++] = temp;

      int nodesLeft = initSize;

      if (leftSize > 0)
      {
        leftSize--;
        nodesLeft++;
      }

      ListNode *prev;

      while (nodesLeft--)
      {
        prev = temp;
        temp = temp->next;
      }

      prev->next = nullptr;
    }

    return result;
  }
};

int main()
{
  return 0;
}