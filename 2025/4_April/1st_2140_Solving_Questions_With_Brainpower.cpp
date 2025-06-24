#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long solve(vector<vector<int>> &questions, int index)
  {
    if (index >= questions.size())
      return 0;

    long long pick = questions[index][0] + solve(questions, index + 1 + questions[index][1]);
    long long notPick = solve(questions, index + 1);

    return max(pick, notPick);
  }

  long long mostPoints(vector<vector<int>> &questions)
  {
    int n = questions.size();

    return solve(questions, 0);
  }

  long long solveMemoization(vector<vector<int>> &questions, int index, vector<long long> &dp)
  {
    if (index >= questions.size())
      return 0;

    if (dp[index] != -1)
      return dp[index];

    long long pick = questions[index][0] + solveMemoization(questions, index + 1 + questions[index][1], dp);
    long long notPick = solveMemoization(questions, index + 1, dp);

    return dp[index] = max(pick, notPick);
  }

  long long mostPointsMemoization(vector<vector<int>> &questions)
  {
    int n = questions.size();

    vector<long long> dp(n, -1);

    return solveMemoization(questions, 0, dp);
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};

  cout << sol.mostPoints(questions) << endl;

  return 0;
}