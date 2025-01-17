#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool doesValidArrayExist(vector<int> &derived)
  {
    int XOR = 0;

    for (auto it : derived)
      XOR ^= it;

    return XOR == 0;
  }
};

int main()
{
  Solution sol;
  vector<int> derived = {};

  return 0;
}