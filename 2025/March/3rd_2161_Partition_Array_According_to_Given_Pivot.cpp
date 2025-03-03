#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> pivotArrayBrute(vector<int> &nums, int pivot)
  {
    vector<int> smallerThanPivot, equalToPivot, greaterThanPivot;

    for (int num : nums)
    {
      if (num < pivot)
        smallerThanPivot.push_back(num);
      else if (num > pivot)
        greaterThanPivot.push_back(num);
      else
        equalToPivot.push_back(num);
    }

    vector<int> result;

    for (auto num : smallerThanPivot)
      result.push_back(num);

    for (auto num : equalToPivot)
      result.push_back(num);

    for (auto num : greaterThanPivot)
      result.push_back(num);

    return result;
  }

  vector<int> pivotArrayOptimal(vector<int> &nums, int pivot)
  {
    int smallerThanPivot = 0, equalToPivot = 0, greaterThanPivot = 0;

    for (int num : nums)
    {
      if (num < pivot)
        smallerThanPivot++;
      else if (num > pivot)
        greaterThanPivot++;
      else
        equalToPivot++;
    }

    vector<int> result(nums.size());

    int indexLeft = 0;
    int indexBetween = smallerThanPivot;
    int indexRight = smallerThanPivot + equalToPivot;

    for (int num : nums)
    {
      if (num < pivot)
        result[indexLeft++] = num;
      else if (num > pivot)
        result[indexRight++] = num;
      else
        result[indexBetween++] = num;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {9, 12, 5, 10, 14, 3, 10};
  int pivot = 10;

  auto ans = sol.pivotArrayBrute(nums, pivot);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.pivotArrayOptimal(nums, pivot);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}