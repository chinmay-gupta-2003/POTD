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
  vector<int> nodesBetweenCriticalPoints(ListNode *head)
  {

    ListNode *curr = head->next;
    ListNode *prev = head;

    int minDist = 1e6, maxDist = 0, prevPosCP = 0, currPos = 1;

    while (curr->next)
    {
      if ((curr->val > prev->val && curr->val > curr->next->val) ||
          (curr->val < prev->val && curr->val < curr->next->val))
      {
        if (prevPosCP)
        {
          minDist = min(minDist, currPos - prevPosCP);
          maxDist += currPos - prevPosCP;
        }

        prevPosCP = currPos;
      }

      prev = curr;
      curr = curr->next;
      currPos++;
    }

    if (maxDist == 0 || minDist == 1e6)
      return {-1, -1};

    return {minDist, maxDist};
  }
};

int main()
{
  return 0;
}