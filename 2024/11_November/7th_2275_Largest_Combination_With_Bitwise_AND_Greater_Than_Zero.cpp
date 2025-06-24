#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    int n = candidates.size();
    int maxSize = 1;

    for (int i = 0; i < 24; i++)
    {
      int cnt = 0;

      for (auto it : candidates)
      {
        if (it & (1 << i))
          cnt++;
      }

      maxSize = max(maxSize, cnt);
    }

    return maxSize;
  }
};

int main()
{
  Solution sol;
  vector<int> candidates = {16, 17, 71, 62, 12, 24, 14};

  cout << sol.largestCombination(candidates);

  return 0;
}