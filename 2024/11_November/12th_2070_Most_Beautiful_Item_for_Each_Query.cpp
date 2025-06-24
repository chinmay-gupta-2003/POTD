#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> maximumBeautyBrute(vector<vector<int>> &items, vector<int> &queries)
  {
    int q = queries.size();
    vector<int> ans;

    for (auto query : queries)
    {
      int maxBeauty = 0;
      for (auto it : items)
      {
        if (it[0] <= query)
          maxBeauty = max(maxBeauty, it[1]);
      }

      ans.push_back(maxBeauty);
    }

    return ans;
  }

  int findEle(vector<vector<int>> &nums, int query)
  {
    int low = 0, high = nums.size() - 1;
    int ans = -1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (nums[mid][0] <= query)
      {
        ans = mid;
        low = mid + 1;
      }
      else
        high = mid - 1;
    }

    return ans;
  }

  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
  {
    sort(items.begin(), items.end());

    int maxBeautySeen = items[0][1];

    for (int i = 1; i < items.size(); i++)
    {
      maxBeautySeen = max(maxBeautySeen, items[i][1]);
      items[i][1] = maxBeautySeen;
    }

    vector<int> ans;
    for (auto it : queries)
    {
      int ele = findEle(items, it);

      if (ele == -1)
        ans.push_back(0);
      else
        ans.push_back(items[ele][1]);
    }

    return ans;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
  vector<int> queries = {1, 2, 3, 4, 5, 6};

  auto ans = sol.maximumBeautyBrute(items, queries);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.maximumBeauty(items, queries);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}