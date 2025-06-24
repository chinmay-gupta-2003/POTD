#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long maximumTripletValueBrute(vector<int> &nums)
  {
    int n = nums.size();
    long long result = 0;

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        for (int k = j + 1; k < n; k++)
          result = max(result, (long long)(nums[i] - nums[j]) * nums[k]);
      }
    }

    return result;
  }

  long long maximumTripletValueBetter(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> leftMax(n, 0), rightMax(n, 0);

    for (int i = 1; i < n - 1; i++)
      leftMax[i] = max(leftMax[i - 1], nums[i - 1]);

    for (int i = n - 2; i >= 1; i--)
      rightMax[i] = max(rightMax[i + 1], nums[i + 1]);

    long long result = 0;

    for (int i = 1; i < n - 1; i++)
      result = max(result, (long long)(leftMax[i] - nums[i]) * rightMax[i]);

    return result;
  }

  long long maximumTripletValueOptimal(vector<int> &nums)
  {
    int n = nums.size();

    long long maxi = 0, maxDiff = 0, result = 0;

    for (int i = 0; i < n; i++)
    {
      result = max(result, maxDiff * nums[i]);

      maxDiff = max(maxDiff, maxi - nums[i]);

      maxi = max(maxi, (long long)nums[i]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {12, 6, 1, 2, 7};

  cout << sol.maximumTripletValueBrute(nums) << endl;
  cout << sol.maximumTripletValueBetter(nums) << endl;
  cout << sol.maximumTripletValueOptimal(nums) << endl;

  return 0;
}