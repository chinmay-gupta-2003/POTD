#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxTwoEvents(vector<vector<int>> &events)
  {
    int n = events.size();
    int maxSum = INT_MIN;

    sort(events.begin(), events.end());

    for (int i = 0; i < n; i++)
    {
      maxSum = max(maxSum, events[i][2]);

      for (int j = i + 1; j < n; j++)
      {
        if (events[j][0] > events[i][1])
          maxSum = max(maxSum, events[j][2] + events[i][2]);
      }
    }

    return maxSum;
  }

  int maxTwoEventsOptimal(vector<vector<int>> &events)
  {
    int n = events.size();
    int maxSum = INT_MIN;

    sort(events.begin(), events.end());

    vector<int> suffixMax(n);

    suffixMax[n - 1] = events[n - 1][2];

    for (int i = n - 2; i >= 0; i--)
      suffixMax[i] = max(events[i][2], suffixMax[i + 1]);

    for (int i = 0; i < n; i++)
    {
      maxSum = max(maxSum, events[i][2]);

      int start = i + 1, end = n - 1, validIndex = -1;

      while (start <= end)
      {
        int mid = start + (end - start) / 2;

        if (events[mid][0] > events[i][1])
        {
          validIndex = mid;
          end = mid - 1;
        }
        else
          start = mid + 1;
      }

      if (validIndex != -1)
        maxSum = max(maxSum, events[i][2] + suffixMax[validIndex]);
    }

    return maxSum;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> events = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};

  cout << sol.maxTwoEvents(events) << endl;
  cout << sol.maxTwoEventsOptimal(events) << endl;

  return 0;
}