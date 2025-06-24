#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximumBeautyBrute(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<pair<int, int>> intervals;

    for (int i = 0; i < n; i++)
      intervals.push_back({nums[i] - k, nums[i] + k});

    sort(intervals.begin(), intervals.end());

    int maxBeauty = -1;

    for (int i = 0; i < n; i++)
    {
      int beauty = 1;

      for (int j = i + 1; j < n; j++)
      {
        if (intervals[i].second < intervals[j].first)
          break;

        beauty++;
      }

      maxBeauty = max(maxBeauty, beauty);
    }

    return maxBeauty;
  }

  int maximumBeautyOptimal(vector<int> &nums, int k)
  {
    int n = nums.size();
    vector<pair<int, int>> intervals;

    for (int i = 0; i < n; i++)
      intervals.push_back({nums[i] - k, nums[i] + k});

    sort(intervals.begin(), intervals.end());

    int maxBeauty = -1;
    queue<int> endQueue;

    for (auto it : intervals)
    {
      while (!endQueue.empty() && endQueue.front() < it.first)
        endQueue.pop();

      endQueue.push(it.second);

      maxBeauty = max(maxBeauty, (int)endQueue.size());
    }

    return maxBeauty;
  }

  int binarySearch(vector<int> &nums, int key, int start)
  {
    int end = nums.size() - 1;

    int ans = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;

      if (nums[mid] <= key)
      {
        ans = mid;
        start = mid + 1;
      }
      else
        end = mid - 1;
    }

    return ans;
  }

  int maximumBeautyOptimal2(vector<int> &nums, int k)
  {
    int n = nums.size();
    int maxBeauty = 1;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
      int limit = nums[i] + 2 * k;

      int index = binarySearch(nums, limit, i + 1);

      if (index != -1)
        maxBeauty = max(maxBeauty, index - i + 1);
    }

    return maxBeauty;
  }
};

int main()
{
  Solution sol;

  int k = 18;
  vector<int> nums = {5, 65, 9, 36, 96, 44, 24, 50, 20, 46, 29};

  cout << sol.maximumBeautyBrute(nums, k) << endl;
  cout << sol.maximumBeautyOptimal(nums, k) << endl;
  cout << sol.maximumBeautyOptimal2(nums, k) << endl;

  return 0;
}