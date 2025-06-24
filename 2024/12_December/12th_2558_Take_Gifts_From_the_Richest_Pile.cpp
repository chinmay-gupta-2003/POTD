#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  long long pickGifts(vector<int> &gifts, int k)
  {
    priority_queue<int> pq;

    for (auto it : gifts)
      pq.push(it);

    while (k--)
    {
      int top = pq.top();
      pq.pop();

      pq.push(floor(sqrt(top)));
    }

    long long sum = 0;

    while (!pq.empty())
    {
      int top = pq.top();
      pq.pop();

      sum += top;
    }

    return sum;
  }
};

int main()
{
  Solution sol;

  vector<int> gifts = {25, 64, 9, 4, 100};
  int k = 4;

  cout << sol.pickGifts(gifts, k);

  return 0;
}