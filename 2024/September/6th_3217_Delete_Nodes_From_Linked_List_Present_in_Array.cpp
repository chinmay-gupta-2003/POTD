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
  ListNode *modifiedList(vector<int> &nums, ListNode *head)
  {
    unordered_set<int> numsSet(nums.begin(), nums.end());

    while (numsSet.find(head->val) != numsSet.end())
      head = head->next;

    ListNode *temp = head;

    while (temp->next)
    {
      if (numsSet.find(temp->next->val) != numsSet.end())
        temp->next = temp->next->next;
      else
        temp = temp->next;
    }

    return head;
  }
};

int main()
{
  return 0;
}