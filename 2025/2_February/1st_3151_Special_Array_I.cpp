#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isArraySpecial(vector<int> &nums)
  {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
      if ((nums[i] + nums[i + 1]) % 2 == 0)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 3, 2, 5};

  cout << sol.isArraySpecial(nums);

  return 0;
}