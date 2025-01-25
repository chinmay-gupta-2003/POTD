#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> lexicographicallySmallestArrayBrute(vector<int> &nums, int limit)
  {
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      int times = n - i - 1;

      while (times--)
      {
        for (int j = i + 1; j < n; j++)
        {
          if (nums[j] < nums[i] && abs(nums[i] - nums[j]) <= limit)
            swap(nums[i], nums[j]);
        }
      }
    }

    return nums;
  }

  vector<int> lexicographicallySmallestArrayOptimal(vector<int> &nums, int limit)
  {
    int n = nums.size();

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end(), greater<>());

    unordered_map<int, vector<int>> membersMap;
    unordered_map<int, int> groupMap;

    int groupNumber = 0;

    for (int i = 0; i < n; i++)
    {
      if (i == 0)
      {
        membersMap[0].push_back(sortedNums[0]);
        groupMap[sortedNums[0]] = 0;
      }

      else if (sortedNums[i - 1] - sortedNums[i] <= limit)
      {
        membersMap[groupNumber].push_back(sortedNums[i]);
        groupMap[sortedNums[i]] = groupNumber;
      }

      else
      {
        groupNumber++;

        membersMap[groupNumber].push_back(sortedNums[i]);
        groupMap[sortedNums[i]] = groupNumber;
      }
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      int group = groupMap[nums[i]];

      result.push_back(membersMap[group].back());
      membersMap[group].pop_back();
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {5, 100, 44, 45, 16, 30, 14, 65, 83, 64};
  int limit = 15;

  auto ans = sol.lexicographicallySmallestArrayBrute(nums, limit);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.lexicographicallySmallestArrayOptimal(nums, limit);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}