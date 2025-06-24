#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumOperations(vector<int> &nums)
  {
    int i = 0, n = nums.size();
    int result = 0;

    while (i < n)
    {
      bool flag = true;
      unordered_set<int> visitedNums;

      for (int j = i; j < n; j++)
      {
        if (visitedNums.find(nums[j]) != visitedNums.end())
        {
          result++;
          i += 3;

          flag = false;

          break;
        }

        visitedNums.insert(nums[j]);
      }

      if (flag)
        break;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 2, 3, 3, 5, 7};

  cout << sol.minimumOperations(nums) << endl;

  return 0;
}