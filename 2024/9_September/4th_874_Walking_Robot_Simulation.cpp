#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
  {

    unordered_set<string> obstaclesSet;

    for (auto it : obstacles)
      obstaclesSet.insert(to_string(it[0]) + '_' + to_string(it[1]));

    int result = 0;
    int direction = 1; // 0->E, 1->N, 2->W, 3->S

    vector<int> coordinates = {0, 0};
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int i = 0; i < commands.size(); i++)
    {
      if (commands[i] == -2)
      {
        if (direction == 3)
          direction = 0;
        else
          direction++;
      }

      else if (commands[i] == -1)
      {
        if (direction == 0)
          direction = 3;
        else
          direction--;
      }

      else
      {
        for (int k = 0; k < commands[i]; k++)
        {
          int newX = coordinates[0] + directions[direction][0];
          int newY = coordinates[1] + directions[direction][1];

          if (obstaclesSet.find(to_string(newX) + '_' + to_string(newY)) == obstaclesSet.end())
          {
            coordinates[0] = newX;
            coordinates[1] = newY;

            result = max(result, newX * newX + newY * newY);
          }
          else
            break;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;

  vector<int> commands = {-2, -1, -2, 3, 7};
  vector<vector<int>> obstacles = {{1, -3}, {2, -3}, {4, 0}, {-2, 5}, {-5, 2}, {0, 0}, {4, -4}, {-2, -5}, {-1, -2}, {0, 2}};

  cout << sol.robotSim(commands, obstacles);

  return 0;
}