#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string removeOccurrencesBrute(string s, string part)
  {
    while (s.find(part) != string::npos)
      s.erase(s.find(part), part.length());

    return s;
  }
};

int main()
{
  Solution sol;
  string s = "axxxxyyyyb", part = "xy";

  cout << sol.removeOccurrencesBrute(s, part) << endl;

  return 0;
}