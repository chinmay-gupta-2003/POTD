#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int shortestSubarrayBrute(vector<int> &nums, int k)
  {
    int n = nums.size();
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
      int sum = 0;

      for (int j = i; j < n; j++)
      {
        sum += nums[j];

        if (sum >= k)
          mini = min(mini, j - i + 1);
      }
    }

    if (mini == INT_MAX)
      return -1;

    return mini;
  }

  int shortestSubarray(vector<int> &nums, int k)
  {
    int n = nums.size();
    int mini = INT_MAX;

    vector<long long> cumulativeSum;
    deque<int> deq;

    int i = 0;
    long long sum = 0;

    while (i < n)
    {
      sum += nums[i];

      cumulativeSum.push_back(sum);

      if (sum >= k)
        mini = min(mini, i + 1);

      while (!deq.empty() && cumulativeSum[i] - cumulativeSum[deq.front()] >= k)
      {
        mini = min(mini, i - deq.front());

        deq.pop_front();
      }

      while (!deq.empty() && cumulativeSum[i] < cumulativeSum[deq.back()])
      {
        deq.pop_back();
      }

      deq.push_back(i);
      i++;
    }

    if (mini == INT_MAX)
      return -1;

    return mini;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {84, 37, 32, 40, 95};
  int k = 167;

  cout << sol.shortestSubarrayBrute(nums, k) << endl;
  cout << sol.shortestSubarray(nums, k) << endl;

  return 0;
}