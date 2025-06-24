#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findLengthOfShortestSubarray(vector<int> &arr)
  {
    int n = arr.size();

    int i = 0, j = n - 1;

    while (j > 0 && arr[j] >= arr[j - 1])
    {
      j--;
    }

    int mini = j;

    if (j == 0)
      return 0;

    while (i < j && (i == 0 || arr[i] >= arr[i - 1]))
    {
      while (j < n && arr[j] < arr[i])
        j++;

      mini = min(mini, j - i - 1);

      i++;
    }

    return mini;
  }
};

int main()
{
  Solution sol;

  vector<int> nums = {1, 2, 3, 10, 4, 2, 3, 5};

  cout << sol.findLengthOfShortestSubarray(nums);

  return 0;
}