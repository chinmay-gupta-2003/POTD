#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> minOperationsBrute(string boxes)
  {
    int n = boxes.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      int cnt = 0;

      for (int j = 0; j < n; j++)
      {
        if (boxes[j] == '1')
          cnt += abs(j - i);
      }

      result.push_back(cnt);
    }

    return result;
  }

  vector<int> minOperationsOptimal(string boxes)
  {
    int n = boxes.size(), oneCount = 0, movesSum = 0;
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      result.push_back(movesSum);

      if (boxes[i] == '1')
        oneCount++;

      movesSum += oneCount;
    }

    oneCount = 0, movesSum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
      result[i] += movesSum;

      if (boxes[i] == '1')
        oneCount++;

      movesSum += oneCount;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string boxes = "001011";

  auto ans = sol.minOperationsBrute(boxes);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}