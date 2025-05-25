#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestPalindrome(vector<string> &words)
  {
    int result = 0;
    unordered_map<string, int> freqMap;

    for (string &word : words)
    {
      string reverseWord = {word[1], word[0]};

      if (freqMap[reverseWord] > 0)
      {
        freqMap[reverseWord]--;
        result += 4;
      }
      else
        freqMap[word]++;
    }

    for (auto &key : freqMap)
    {
      if (key.first[0] == key.first[1] && key.second > 0)
      {
        result += 2;
        break;
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"dd", "aa", "bb", "dd", "aa", "dd", "bb", "dd", "aa", "cc", "bb", "cc", "dd", "cc"};

  cout << sol.longestPalindrome(words) << endl;

  return 0;
}