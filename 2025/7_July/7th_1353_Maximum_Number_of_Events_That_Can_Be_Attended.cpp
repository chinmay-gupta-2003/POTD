#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxEvents(vector<vector<int>> &events)
  {
    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = events.size();
    int maxDay = 0;

    for (auto event : events)
    {
      maxDay = max(maxDay, event[1]);
    }

    int i = 0, currentDay = events[0][0], result = 0;

    while (currentDay <= maxDay)
    {
      while (i < n && events[i][0] == currentDay)
      {
        minHeap.push(events[i][1]);
        i++;
      }

      while (!minHeap.empty() && minHeap.top() < currentDay)
        minHeap.pop();

      if (!minHeap.empty())
      {
        minHeap.pop();
        result++;
      }

      currentDay++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> events = {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};

  cout << sol.maxEvents(events) << endl;

  return 0;
}