#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool check(vector<int> &nums)
  {
    int n = nums.size(), cnt = 0;

    if (nums[n - 1] > nums[0])
      cnt++;

    for (int i = 0; i < n - 1; i++)
    {
      if (nums[i] > nums[i + 1])
        cnt++;
    }

    return cnt <= 1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 1, 2, 3, 4, 5};

  cout << sol.check(nums);

  return 0;
}