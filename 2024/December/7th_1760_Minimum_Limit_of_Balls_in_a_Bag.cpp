#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isPossible(vector<int> &nums, int maxOperations, int penalty)
  {
    int operations = 0;

    for (auto it : nums)
    {
      if (it > penalty)
        operations += ceil((double)it / penalty) - 1;

      if (operations > maxOperations)
        return false;
    }

    return true;
  }

  int minimumSize(vector<int> &nums, int maxOperations)
  {
    int start = 1, end = *max_element(nums.begin(), nums.end());
    int ans = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;

      if (isPossible(nums, maxOperations, mid))
      {
        ans = mid;
        end = mid - 1;
      }
      else
        start = mid + 1;
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {2, 4, 8, 2};
  int maxOperations = 4;

  cout << sol.minimumSize(nums, maxOperations);

  return 0;
}