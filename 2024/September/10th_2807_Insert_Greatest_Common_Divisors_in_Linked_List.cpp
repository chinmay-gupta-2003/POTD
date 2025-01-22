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
  int findGCD(int x, int y)
  {
    while (x > 0 && y > 0)
    {
      if (x > y)
        x = x % y;
      else
        y = y % x;
    }

    if (x == 0)
      return y;

    return x;
  }

  ListNode *insertGreatestCommonDivisors(ListNode *head)
  {
    ListNode *dummy = head;

    while (dummy->next)
    {
      // ListNode* gcdNode =
      //     new ListNode(gcd(dummy->val, dummy->next->val));

      ListNode *gcdNode =
          new ListNode(findGCD(dummy->val, dummy->next->val));

      gcdNode->next = dummy->next;

      dummy->next = gcdNode;

      dummy = gcdNode->next;
    }

    return head;
  }
};

int main()
{
  return 0;
}