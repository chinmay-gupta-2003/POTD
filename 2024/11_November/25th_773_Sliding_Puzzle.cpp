#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int slidingPuzzle(vector<vector<int>> &board)
  {
    string start = "", end = "123450";

    queue<string> q;
    unordered_set<string> visisted;

    vector<vector<int>> swapping = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        start += to_string(board[i][j]);
      }
    }

    int level = 0;
    q.push(start);
    visisted.insert(start);

    while (!q.empty())
    {
      int n = q.size();

      while (n--)
      {
        string front = q.front();
        q.pop();

        if (front == end)
          return level;

        int zeroIndex = front.find('0');

        for (auto swapIndex : swapping[zeroIndex])
        {
          string newSeq = front;

          swap(newSeq[zeroIndex], newSeq[swapIndex]);

          if (visisted.find(newSeq) == visisted.end())
          {
            visisted.insert(newSeq);
            q.push(newSeq);
          }
        }
      }

      level++;
    }

    return -1;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> board = {{4, 1, 2}, {5, 0, 3}};

  cout << sol.slidingPuzzle(board);

  return 0;
}