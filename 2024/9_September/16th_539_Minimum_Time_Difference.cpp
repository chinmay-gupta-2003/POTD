#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMinDifference(vector<string> &timePoints)
  {
    int n = timePoints.size();
    vector<int> minutesArray;

    for (auto formatTime : timePoints)
    {
      int hrs = stoi(formatTime.substr(0, 2));
      int mins = stoi(formatTime.substr(3, 2));

      int time = hrs * 60 + mins;

      minutesArray.push_back(time);
    }

    sort(minutesArray.begin(), minutesArray.end());

    int result = 1440;

    for (int i = 1; i < n; i++)
      result = min(result, minutesArray[i] - minutesArray[i - 1]);

    result = min(result, 1440 - minutesArray[n - 1] + minutesArray[0]);

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> timePoints = {"23:59", "00:00"};

  cout << sol.findMinDifference(timePoints);

  return 0;
}