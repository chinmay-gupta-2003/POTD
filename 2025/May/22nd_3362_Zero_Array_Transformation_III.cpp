#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries)
  {
    sort(queries.begin(), queries.end());

    int q = queries.size();

    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int j = 0, queriesUsed = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      while (j < q && queries[j][0] == i)
      {
        maxHeap.push(queries[j][1]);
        j++;
      }

      nums[i] -= minHeap.size();

      while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i)
      {
        int end = maxHeap.top();
        maxHeap.pop();

        nums[i]--;
        queriesUsed++;

        minHeap.push(end);
      }

      if (nums[i] > 0)
        return -1;

      while (!minHeap.empty() && minHeap.top() <= i)
        minHeap.pop();
    }

    return q - queriesUsed;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 3, 2, 1};
  vector<vector<int>> queries = {{1, 3}, {0, 2}};

  cout << sol.maxRemoval(nums, queries) << endl;

  return 0;
}