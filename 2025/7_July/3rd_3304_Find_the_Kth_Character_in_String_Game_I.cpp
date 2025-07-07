#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string getExtension(string &word)
  {
    string extension = "";

    for (int i = 0; i < word.size(); i++)
    {
      if (word[i] == 'z')
        extension.push_back('a');
      else
        extension.push_back(word[i] + 1);
    }

    return extension;
  }

  char kthCharacter(int k)
  {
    string word = "a";

    while (word.size() < k)
    {
      string extension = getExtension(word);

      word += extension;
    }

    return word[k - 1];
  }

  int countSetBits(int num)
  {
    int setBits = 0;

    while (num)
    {
      if (num & 1)
        setBits++;

      num = num >> 1;
    }

    return setBits;
  }

  char kthCharacterOptimal(int k)
  {
    int numberOfShift = countSetBits(k - 1);

    return 'a' + numberOfShift;
  }
};

int main()
{
  Solution sol;
  int k = 10;

  cout << sol.kthCharacter(k) << endl;
  cout << sol.kthCharacterOptimal(k) << endl;

  return 0;
}