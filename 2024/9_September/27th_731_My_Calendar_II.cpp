#include <bits/stdc++.h>
using namespace std;

class MyCalendarTwo
{
public:
  vector<pair<int, int>> events;
  vector<pair<int, int>> doubleBookedEvents;

  bool checkOverlap(int s1, int e1, int s2, int e2)
  {
    return max(s1, s2) < min(e1, e2);
  }

  pair<int, int> getOverlap(int s1, int e1, int s2, int e2)
  {
    return {max(s1, s2), min(e1, e2)};
  }

  bool book(int startTime, int endTime)
  {
    for (auto event : doubleBookedEvents)
    {
      if (checkOverlap(event.first, event.second, startTime, endTime))
        return false;
    }

    for (auto event : events)
    {
      if (checkOverlap(event.first, event.second, startTime, endTime))
        doubleBookedEvents.push_back(getOverlap(event.first, event.second, startTime, endTime));
    }

    events.push_back({startTime, endTime});
    return true;
  }
};