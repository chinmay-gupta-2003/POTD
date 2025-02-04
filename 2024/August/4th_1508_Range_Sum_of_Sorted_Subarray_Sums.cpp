#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, int> P;

  int mod = 1e9 + 7;

  int rangeSumBrute(vector<int> &nums, int n, int left, int right)
  {
    vector<int> subArraySum;

    for (int i = 0; i < n; i++)
    {
      int sum = 0;

      for (int j = i; j < n; j++)
      {
        sum += nums[j];

        subArraySum.push_back(sum);
      }
    }

    sort(subArraySum.begin(), subArraySum.end());

    int result = 0;

    for (int i = left - 1; i <= right - 1; i++)
      result = (result + subArraySum[i]) % mod;

    return result;
  }

  int rangeSumBetter(vector<int> &nums, int n, int left, int right)
  {
    priority_queue<P, vector<P>, greater<P>> pq;

    for (int i = 0; i < n; i++)
      pq.push({nums[i], i});

    int result = 0;

    for (int counter = 1; counter <= right; counter++)
    {
      auto top = pq.top();
      pq.pop();

      int num = top.first;
      int index = top.second;

      if (counter >= left)
        result = (result + num) % mod;

      int newIndex = index + 1;

      if (newIndex < n)
        pq.push({num + nums[newIndex], newIndex});
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4};
  int n = 4, left = 3, right = 5;

  cout << sol.rangeSumBrute(nums, n, left, right) << endl;
  cout << sol.rangeSumBetter(nums, n, left, right) << endl;

  return 0;
}