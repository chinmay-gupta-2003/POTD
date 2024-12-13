#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long findScore(vector<int> &nums)
  {
    int n = nums.size();

    vector<int> marked(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
      pq.push({nums[i], i});

    long long score = 0;

    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();

      if (marked[top.second])
        continue;

      score += top.first;

      if (top.second > 0)
        marked[top.second - 1] = 1;

      if (top.second < n - 1)
        marked[top.second + 1] = 1;
    }

    return score;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 3, 5, 1, 3, 2};

  cout << sol.findScore(nums);

  return 0;
}