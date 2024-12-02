#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int isPrefixOfWord(string sentence, string searchWord)
  {
    stringstream ss(sentence);
    string word;

    int pos = 1, searchSize = searchWord.size();

    while (ss >> word)
    {
      if (searchSize <= word.size() && (word.substr(0, searchSize) == searchWord))
        return pos;

      pos++;
    }

    return -1;
  }
};

int main()
{
  Solution sol;
  string sentence = "i love eating burger", searchWord = "burg";

  cout << sol.isPrefixOfWord(sentence, searchWord);

  return 0;
}