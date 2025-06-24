#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isCircularSentence(string sentence)
  {
    int cnt = 0;

    for (int i = 0; i < sentence.length(); i++)
    {
      if (sentence[i] == ' ')
      {
        if (sentence[i - 1] != sentence[i + 1])
          return false;
      }
    }

    return sentence[0] == sentence[sentence.length() - 1];
  }
};

int main()
{
  Solution sol;
  string s = "eetcode";

  cout << sol.isCircularSentence(s);

  return 0;
}