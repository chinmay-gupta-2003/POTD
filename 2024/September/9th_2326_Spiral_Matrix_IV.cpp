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
  vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
  {
    vector<vector<int>> result(m, vector<int>(n, -1));

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right && head)
    {
      for (int i = left; i <= right; i++)
      {
        if (!head)
          return result;

        result[top][i] = head->val;
        head = head->next;
      }

      top++;

      for (int i = top; i <= bottom; i++)
      {
        if (!head)
          return result;

        result[i][right] = head->val;
        head = head->next;
      }

      right--;

      if (top <= bottom)
      {
        for (int i = right; i >= left; i--)
        {
          if (!head)
            return result;

          result[bottom][i] = head->val;
          head = head->next;
        }

        bottom--;
      }

      if (left <= right)
      {
        for (int i = bottom; i >= top; i--)
        {
          if (!head)
            return result;

          result[i][left] = head->val;
          head = head->next;
        }

        left++;
      }
    }

    return result;
  }
};

int main()
{
  return 0;
}