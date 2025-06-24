#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findKDistantIndicesBrute(vector<int> &nums, int key, int k)
  {
    int n = nums.size();

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (nums[j] == key && abs(i - j) <= k)
        {
          result.push_back(i);
          break;
        }
      }
    }

    return result;
  }

  vector<int> findKDistantIndicesOptimal(vector<int> &nums, int key, int k)
  {
    int n = nums.size();

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      if (nums[i] == key)
      {
        int l = max(0, i - k);

        if (result.size() && (result.back() >= l))
          l = result.back() + 1;

        int r = min(n - 1, i + k);

        for (int j = l; j <= r; j++)
          result.push_back(j);
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {2, 2, 2, 2, 2};
  int key = 2, k = 2;

  auto ans = sol.findKDistantIndicesBrute(nums, key, k);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.findKDistantIndicesOptimal(nums, key, k);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}