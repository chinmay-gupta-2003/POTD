#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> findWordsContaining(vector<string> &words, char x)
  {
    vector<int> result;

    for (int i = 0; i < words.size(); i++)
    {
      if (words[i].find(x) != string::npos)
        result.push_back(i);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"abc", "bcd", "aaaa", "cbc"};
  char x = 'a';

  auto ans = sol.findWordsContaining(words, x);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}