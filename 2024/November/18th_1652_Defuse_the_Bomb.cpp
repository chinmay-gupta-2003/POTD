#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int getSum(int i, int k, vector<int> &nums)
  {
    int n = nums.size();
    int step = abs(k);

    if (k == 0)
      return 0;

    int sum = 0;

    if (k > 0)
    {
      int j = i + 1;

      while (step--)
      {
        if (j >= n)
          j = j % n;

        sum += nums[j];

        j++;
      }
    }
    else
    {
      int j = i - 1;

      while (step--)
      {
        if (j < 0)
          j = j + n;

        sum += nums[j];

        j--;
      }
    }

    return sum;
  }

  vector<int> decrypt(vector<int> &code, int k)
  {
    int n = code.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
      int sum = getSum(i, k, code);

      ans.push_back(sum);
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {2, 4, 9, 3};
  int k = -2;

  auto ans = sol.decrypt(nums, k);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}