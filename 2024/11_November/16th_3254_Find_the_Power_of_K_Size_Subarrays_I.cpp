#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> resultsArrayBrute(vector<int> &nums, int k)
  {
    int n = nums.size();

    vector<int> ans(n - k + 1);

    for (int i = 0; i <= n - k; i++)
    {
      ans[i] = nums[i];
      bool flag = false;

      for (int j = i + 1; j < i + k; j++)
      {
        if (nums[j] != nums[j - 1] + 1)
        {
          flag = true;
          break;
        }

        ans[i] = nums[j];
      }

      if (flag)
        ans[i] = -1;
    }

    return ans;
  }

  vector<int> resultsArray(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<int> ans(n - k + 1, -1);

    int count = 1;

    for (int i = 1; i < k; i++)
    {
      if (nums[i] == nums[i - 1] + 1)
        count++;
      else
        count = 1;
    }

    if (count == k)
      ans[0] = nums[k - 1];

    int i = 1, j = k;

    while (j < n)
    {
      if (nums[j] == nums[j - 1] + 1)
        count++;
      else
        count = 1;

      if (count >= k)
        ans[i] = nums[j];

      i++;
      j++;
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {1, 2, 3, 4, 3, 2, 5};
  int k = 3;

  auto ans = sol.resultsArrayBrute(nums, k);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.resultsArray(nums, k);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}