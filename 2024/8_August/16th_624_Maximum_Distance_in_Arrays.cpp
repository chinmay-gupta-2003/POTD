#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDistanceBrute(vector<vector<int>> &arrays)
  {
    int n = arrays.size();
    int result = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int n1 = arrays[i].size();

      for (int j = i + 1; j < n; j++)
      {
        int n2 = arrays[j].size();

        int diffOne = abs(arrays[i][0] - arrays[j][n2 - 1]);
        int diffTwo = abs(arrays[i][n1 - 1] - arrays[j][0]);

        result = max({diffOne, diffTwo, result});
      }
    }

    return result;
  }

  int maxDistanceOptimal(vector<vector<int>> &arrays)
  {
    int n = arrays.size();

    int mini = INT_MAX, maxi = INT_MIN;
    int result = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int m = arrays[i].size();

      if (i == 0)
      {
        mini = arrays[i][0];
        maxi = arrays[i][m - 1];

        continue;
      }

      int diffOne = abs(arrays[i][0] - maxi);
      int diffTwo = abs(arrays[i][m - 1] - mini);

      result = max({result, diffOne, diffTwo});

      maxi = max(maxi, arrays[i][m - 1]);
      mini = min(mini, arrays[i][0]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> arrays = {{-1, 2, 3}, {4, 5}, {1, 2, 3}};

  cout << sol.maxDistanceBrute(arrays) << endl;
  cout << sol.maxDistanceOptimal(arrays) << endl;

  return 0;
}