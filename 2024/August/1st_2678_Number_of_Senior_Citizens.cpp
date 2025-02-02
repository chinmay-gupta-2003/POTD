#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSeniors(vector<string> &details)
  {
    int result = 0;

    for (string detail : details)
    {
      string age = detail.substr(11, 2);

      if (stoi(age) > 60)
        result++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> details = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};

  cout << sol.countSeniors(details);

  return 0;
}