#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestSquareStreakBrute(vector<int> &nums)
  {
    int n = nums.size(), maxi = -1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
      int curr = nums[i];
      int cnt = 1;

      for (int j = i + 1; j < n; j++)
      {
        if (nums[j] != (long long)curr * curr)
          continue;

        curr = nums[j];
        cnt++;
      }

      if (cnt > 1)
        maxi = max(maxi, cnt);
    }

    return maxi;
  }

  int longestSquareStreakOptimal(vector<int> &nums)
  {
    int n = nums.size(), maxi = -1;
    unordered_set<long long> s;

    for (auto it : nums)
      s.insert(it);

    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      int x = nums[i];

      int root = (int)sqrt(x);

      if ((long long)root * root == x && s.find(root) != s.end())
        continue;

      while (s.find(x) != s.end())
      {
        cnt++;
        x = (long long)x * x;

        if (x > 1e5)
          break;
      }

      if (cnt > 1)
        maxi = max(maxi, cnt);
    }

    return maxi;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {4, 3, 6, 16, 8, 2};

  cout << sol.longestSquareStreakBrute(arr) << endl;
  cout << sol.longestSquareStreakOptimal(arr) << endl;

  return 0;
}