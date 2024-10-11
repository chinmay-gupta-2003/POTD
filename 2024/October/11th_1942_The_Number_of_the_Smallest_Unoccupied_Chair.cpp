#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int smallestChairBrute(vector<vector<int>> &times, int targetFriend)
  {
    int n = times.size();
    int targetFriendArrivalTime = times[targetFriend][0];
    vector<int> chairs(n, -1);

    sort(times.begin(), times.end());

    for (auto it : times)
    {
      int arrival = it[0], departure = it[1];

      for (int i = 0; i < n; i++)
      {
        if (chairs[i] <= departure)
        {
          chairs[i] = departure;

          if (arrival == targetFriendArrivalTime)
            return i;

          break;
        }
      }
    }

    return 0;
  }

  int smallestChairOptimal(vector<vector<int>> &times, int targetFriend)
  {
    int n = times.size();
    int targetFriendArrivalTime = times[targetFriend][0];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ocuupiedChair;
    priority_queue<int, vector<int>, greater<int>> freeChair;

    sort(times.begin(), times.end());

    int currentChair = 0;

    for (auto it : times)
    {
      int arrival = it[0], departure = it[1];

      while (!ocuupiedChair.empty() && ocuupiedChair.top().first <= arrival)
      {
        freeChair.push(ocuupiedChair.top().second);
        ocuupiedChair.pop();
      }

      if (!freeChair.empty())
      {
        ocuupiedChair.push({departure, freeChair.top()});
        freeChair.pop();
      }
      else
        ocuupiedChair.push({departure, currentChair++});

      if (arrival == targetFriendArrivalTime)
        return ocuupiedChair.top().second;
    }

    return 0;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> times = {{1, 2}, {2, 3}, {3, 4}};
  int target = 2;

  cout << sol.smallestChairBrute(times, target) << endl;
  cout << sol.smallestChairOptimal(times, target) << endl;

  return 0;
}