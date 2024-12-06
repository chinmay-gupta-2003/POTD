#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxCount(vector<int> &banned, int n, int maxSum)
  {
    int cnt = 0, sum = 0;
    unordered_set<int> bannedSet;

    for (auto it : banned)
      bannedSet.insert(it);

    for (int i = 1; i <= min(maxSum, n); i++)
    {
      if (bannedSet.find(i) == bannedSet.end() && sum + i <= maxSum)
      {
        cnt++;
        sum += i;
      }
    }

    return cnt;
  }
};

int main()
{
  Solution sol;

  vector<int> banned = {1, 2, 3, 4, 5, 6, 7};
  int n = 8, maxSum = 1;

  cout << sol.maxCount(banned, n, maxSum);

  return 0;
}