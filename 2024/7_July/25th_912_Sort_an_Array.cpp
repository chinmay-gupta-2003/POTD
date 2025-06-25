#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void mergeArrays(int start, int end, vector<int> &nums)
  {
    int mid = start + (end - start) / 2;
    int l = start, r = mid + 1;

    vector<int> temp;

    while (l <= mid && r <= end)
    {
      if (nums[l] < nums[r])
        temp.push_back(nums[l++]);
      else
        temp.push_back(nums[r++]);
    }

    while (l <= mid)
    {
      temp.push_back(nums[l++]);
    }

    while (r <= end)
    {
      temp.push_back(nums[r++]);
    }

    for (int i = start, j = 0; i <= end; i++, j++)
    {
      nums[i] = temp[j];
    }
  }

  void merge(int start, int end, vector<int> &nums)
  {
    if (start >= end)
      return;

    int mid = start + (end - start) / 2;

    merge(start, mid, nums);
    merge(mid + 1, end, nums);

    mergeArrays(start, end, nums);
  }

  vector<int> sortArray(vector<int> &nums)
  {
    int start = 0, end = nums.size() - 1;

    merge(start, end, nums);

    return nums;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {6, 9, 4, 2};

  auto ans = sol.sortArray(nums);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}