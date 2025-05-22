#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  double averageWaitingTime(vector<vector<int>> &customers)
  {
    double prevCompletionTime = customers[0][0], totalWaitingTime = 0;

    for (auto it : customers)
    {
      double arrivalTime = it[0], serviceTime = it[1];

      if (prevCompletionTime > arrivalTime)
        totalWaitingTime += prevCompletionTime - arrivalTime;

      totalWaitingTime += serviceTime;

      if (prevCompletionTime > arrivalTime)
        prevCompletionTime += serviceTime;
      else
        prevCompletionTime = arrivalTime + serviceTime;
    }

    return (double)totalWaitingTime / customers.size();
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> customers = {{5, 2}, {5, 4}, {10, 3}, {20, 1}};

  cout << sol.averageWaitingTime(customers) << endl;

  return 0;
}