#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
  {
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> pairs = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};

  auto ans = sol.validArrangement(pairs);

  for (auto it : ans)
  {
    for (auto pair : it)
      cout << pair << " ";

    cout << "   ";
  }

  return 0;
}