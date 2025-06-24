#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int num : nums)
      pq.push(num);

    int result = 0;

    while (pq.top() < k)
    {
      result++;

      long long x = pq.top();
      pq.pop();
      long long y = pq.top();
      pq.pop();

      pq.push(min(x, y) * 2 + max(x, y));
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 11, 10, 1, 3};
  int k = 10;

  cout << sol.minOperations(nums, k) << endl;

  return 0;
}