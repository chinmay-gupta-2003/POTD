#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> uncommonFromSentences(string s1, string s2)
  {
    unordered_map<string, int> wordsMap;

    stringstream ss(s1 + " " + s2);
    string word;

    while (ss >> word)
      wordsMap[word]++;

    vector<string> result;

    for (auto pairs : wordsMap)
    {
      if (pairs.second == 1)
        result.push_back(pairs.first);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s1 = "this apple sweet is sweet", s2 = "this apple is sour";

  auto ans = sol.uncommonFromSentences(s1, s2);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}