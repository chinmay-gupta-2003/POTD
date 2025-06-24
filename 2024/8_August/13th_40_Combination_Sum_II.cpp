#include <bits/stdc++.h>
using namespace std;

class Solution
{
  void solve(int index, int target, vector<int> &candidates, vector<vector<int>> &result, vector<int> &path)
  {
    if (target < 0)
      return;

    if (target == 0)
    {
      result.push_back(path);

      return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
      if (i > index && candidates[i] == candidates[i - 1])
        continue;

      path.push_back(candidates[i]);
      solve(i + 1, target - candidates[i], candidates, result, path);
      path.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
  {
    int n = candidates.size();

    vector<int> path;
    vector<vector<int>> result;

    sort(candidates.begin(), candidates.end());

    solve(0, target, candidates, result, path);

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;

  auto ans = sol.combinationSum2(candidates, target);

  for (auto it : ans)
  {
    for (auto num : it)
      cout << num << " ";

    cout << endl;
  }

  cout << endl;

  return 0;
}