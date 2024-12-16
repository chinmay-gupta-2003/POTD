#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    int n = nums.size();

    vector<int> result = nums;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
      pq.push({nums[i], i});

    while (k--)
    {
      auto top = pq.top();
      pq.pop();

      result[top.second] = top.first * multiplier;
      pq.push({result[top.second], top.second});
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 1, 3, 5, 6};
  int k = 5, multiplier = 2;

  auto ans = sol.getFinalState(nums, k, multiplier);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}