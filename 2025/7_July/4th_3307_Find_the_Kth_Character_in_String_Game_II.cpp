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

  char kthCharacter(long long k, vector<int> &operations)
  {
    string word = "a";

    for (int operate : operations)
    {
      if (operate == 0)
        word += word;
      else
      {

        string extension = getExtension(word);

        word += extension;
      }

      if (word.size() >= k)
        break;
    }

    return word[k - 1];
  }

  char kthCharacterOptimal(long long k, vector<int> &operations)
  {
    if (k == 1)
      return 'a';

    long long length = 1, operateType = -1, newK = -1;

    for (int operate : operations)
    {
      length *= 2;

      if (length >= k)
      {
        operateType = operate;
        newK = k - length / 2;

        break;
      }
    }

    char ch = kthCharacterOptimal(newK, operations);

    if (operateType == 1)
    {
      if (ch == 'z')
        return 'a';

      return ch + 1;
    }

    return ch;
  }
};

int main()
{
  Solution sol;
  long long k = 10;
  vector<int> operations = {0, 1, 0, 1};

  cout << sol.kthCharacter(k, operations) << endl;
  cout << sol.kthCharacterOptimal(k, operations) << endl;

  return 0;
}