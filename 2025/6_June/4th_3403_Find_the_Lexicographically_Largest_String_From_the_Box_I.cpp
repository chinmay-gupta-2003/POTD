#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string answerString(string word, int numFriends)
  {
    if (numFriends == 1)
      return word;

    int n = word.length(), maxLength = n - numFriends + 1;

    char largestChar = 'a';

    for (int i = 0; i < n; i++)
    {
      if (word[i] > largestChar)
        largestChar = word[i];
    }

    string result = "";

    for (int i = 0; i < n; i++)
    {
      if (word[i] == largestChar)
        result = max(result, word.substr(i, min(n - i, maxLength)));
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string word = "nbjnc";
  int numFriends = 2;

  cout << sol.answerString(word, numFriends) << endl;

  return 0;
}