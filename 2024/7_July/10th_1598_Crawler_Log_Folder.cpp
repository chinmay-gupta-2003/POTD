#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minOperations(vector<string> &logs)
  {
    int nested = 0;

    for (string &log : logs)
    {
      if (log[0] != '.')
        nested++;
      else if (log[0] == '.' && log[1] == '.' && nested)
        nested--;
    }

    return nested;
  }
};

int main()
{
  Solution sol;
  vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};

  cout << sol.minOperations(logs);

  return 0;
}