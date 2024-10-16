#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    priority_queue<pair<int, char>> pq;
    string happtStr = "";

    if (a > 0)
      pq.push({a, 'a'});

    if (b > 0)
      pq.push({b, 'b'});

    if (c > 0)
      pq.push({c, 'c'});

    while (!pq.empty())
    {
      auto top = pq.top();
      int currCharCount = top.first;
      char currChar = top.second;
      pq.pop();

      int happyStrLen = happtStr.length();

      if (happyStrLen >= 2 && happtStr[happyStrLen - 1] == currChar && happtStr[happyStrLen - 2] == currChar)
      {
        if (pq.empty())
          break;

        auto top = pq.top();
        int nextCharCount = top.first;
        int nextChar = top.second;
        pq.pop();

        happtStr.push_back(nextChar);
        nextCharCount--;

        if (nextCharCount > 0)
          pq.push({nextCharCount, nextChar});
      }
      else
      {
        happtStr.push_back(currChar);
        currCharCount--;
      }

      if (currCharCount > 0)
        pq.push({currCharCount, currChar});
    }

    return happtStr;
  }
};

int main()
{
  Solution sol;
  int a = 1, b = 1, c = 7;

  cout << sol.longestDiverseString(a, b, c);

  return 0;
}