#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long dividePlayersBrute(vector<int> &skill)
  {
    long long n = skill.size(), totalSum = 0, teams = n / 2;

    for (auto it : skill)
      totalSum += it;

    if (totalSum % teams)
      return -1;

    sort(skill.begin(), skill.end());

    long long i = 0, j = n - 1, chemistry = 0;

    while (i < j)
    {
      if (skill[i] + skill[j] != totalSum / teams)
        return -1;

      chemistry += (skill[i++] * skill[j--]);
    }

    return chemistry;
  }

  long long dividePlayersOptimal(vector<int> &skill)
  {
    long long n = skill.size(), totalSum = 0, teams = n / 2;

    for (auto it : skill)
      totalSum += it;

    if (totalSum % teams)
      return -1;

    long long chemistry = 0, cnt = 0;
    unordered_map<int, int> mp;

    for (auto it : skill)
    {
      int req = (totalSum / teams) - it;

      if (mp[req] > 0)
      {
        chemistry += it * req;

        cnt++;
        mp[req]--;
      }
      else
        mp[it]++;
    }

    if (cnt != teams)
      return -1;

    return chemistry;
  }
};

int main()
{

  Solution sol;

  vector<int> skill = {2, 1, 5, 2};

  cout << sol.dividePlayersBrute(skill) << endl;
  cout << sol.dividePlayersOptimal(skill) << endl;

  return 0;
}