#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dp[2][101][101];

  int solveForAlice(int player, int index, int M, vector<int> &piles)
  {
    if (index >= piles.size())
      return 0;

    int stones = 0;
    int result;

    if (player == 1)
      result = INT_MIN;
    else
      result = INT_MAX;

    for (int x = 1; x <= min(2 * M, (int)piles.size() - index); x++)
    {
      stones += piles[index + x - 1];

      if (player == 1)
        result = max(result, stones + solveForAlice(0, index + x, max(M, x), piles));
      else
        result = min(result, solveForAlice(1, index + x, max(M, x), piles));
    }

    return result;
  }

  int solveForAliceMemoization(int player, int index, int M, vector<int> &piles)
  {
    if (index >= piles.size())
      return 0;

    if (dp[player][index][M] != -1)
      return dp[player][index][M];

    int stones = 0;
    int result;

    if (player == 1)
      result = INT_MIN;
    else
      result = INT_MAX;

    for (int x = 1; x <= min(2 * M, (int)piles.size() - index); x++)
    {
      stones += piles[index + x - 1];

      if (player == 1)
        result = max(result, stones + solveForAliceMemoization(0, index + x, max(M, x), piles));
      else
        result = min(result, solveForAliceMemoization(1, index + x, max(M, x), piles));
    }

    return dp[player][index][M] = result;
  }

  int stoneGameIIBrute(vector<int> &piles, int M)
  {
    return solveForAlice(1, 0, M, piles);
  }

  int stoneGameIIMemoization(vector<int> &piles, int M)
  {
    memset(dp, -1, sizeof(dp));

    return solveForAliceMemoization(1, 0, M, piles);
  }
};

int main()
{
  Solution sol;
  vector<int> piles = {2, 7, 9, 4, 4};
  int M = 1;

  cout << sol.stoneGameIIBrute(piles, M) << endl;
  cout << sol.stoneGameIIMemoization(piles, M) << endl;

  return 0;
}