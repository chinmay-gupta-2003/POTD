#include <bits/stdc++.h>
using namespace std;

class MyCalendar
{
public:
  vector<pair<int, int>> events;

  bool bookBrute(int startTime, int endTime)
  {
    for (auto time : events)
    {
      if (startTime < time.second && endTime > time.first)
        return false;
    }

    events.push_back({startTime, endTime});

    return true;
  }

  set<pair<int, int>> s;

  bool bookOptimal(int startTime, int endTime)
  {
    if (!s.empty())
    {
      auto it = s.lower_bound({startTime, endTime});

      if (it != s.end() && it->first < endTime)
        return false;

      if (it != s.begin() && prev(it)->second > startTime)
        return false;
    }

    s.insert({startTime, endTime});

    return true;
  }
};

int main()
{
  return 0;
}