#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int smallestDistancePairBrute(vector<int> &nums, int k)
  {
    int n = nums.size();

    priority_queue<int> pq;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        pq.push(abs(nums[i] - nums[j]));

        if (pq.size() > k)
          pq.pop();
      }
    }

    return pq.top();
  }

  int smallestDistancePairBetter(vector<int> &nums, int k)
  {
    int n = nums.size();
    int size = *max_element(nums.begin(), nums.end());
    vector<int> distFreq(size + 1, 0);

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
        distFreq[abs(nums[i] - nums[j])]++;
    }

    int result = 0;

    while (k > distFreq[result])
    {
      k -= distFreq[result];

      if (k == 0)
        return result;

      result++;
    }

    return result;
  }

  int countPairs(vector<int> &nums, int diff)
  {
    int i = 0, j = 1, n = nums.size();

    int pairs = 0;

    while (j < n)
    {
      while (nums[j] - nums[i] > diff)
        i++;

      if (i == j)
      {
        j++;
        continue;
      }

      pairs += j - i;

      j++;
    }

    return pairs;
  }

  int smallestDistancePairOptimal(vector<int> &nums, int k)
  {
    int n = nums.size();
    int left = 0, right = *max_element(nums.begin(), nums.end());

    sort(nums.begin(), nums.end());

    int result;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      int pairs = countPairs(nums, mid);

      if (pairs >= k)
      {
        result = mid;
        right = mid - 1;
      }
      else
        left = mid + 1;
    }

    return result;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {1, 6, 1};
  int k = 3;

  cout << sol.smallestDistancePairBrute(nums, k) << endl;
  cout << sol.smallestDistancePairBetter(nums, k) << endl;
  cout << sol.smallestDistancePairOptimal(nums, k) << endl;

  return 0;
}