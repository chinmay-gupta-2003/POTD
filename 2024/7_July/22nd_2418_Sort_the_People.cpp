#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights)
  {
    map<int, string> heightMap;

    for (int i = 0; i < heights.size(); i++)
      heightMap[heights[i]] = names[i];

    vector<string> result;

    for (auto it : heightMap)
      result.push_back(it.second);

    reverse(result.begin(), result.end());

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> names = {"Mary", "John", "Mary"};
  vector<int> heights = {180, 165, 170};

  auto ans = sol.sortPeople(names, heights);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}