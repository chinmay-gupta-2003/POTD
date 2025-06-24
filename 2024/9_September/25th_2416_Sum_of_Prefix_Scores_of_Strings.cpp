#include <bits/stdc++.h>
using namespace std;

struct trieNode
{
  int freq = 0;
  trieNode *children[26] = {nullptr};
};

class Solution
{
public:
  vector<int> sumPrefixScoresBrute(vector<string> &words)
  {
    int n = words.size();

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      int matchedPrefix = 0;

      for (int j = 1; j <= words[i].length(); j++)
      {
        string prefix = words[i].substr(0, j);

        for (int i = 0; i < n; i++)
        {
          if (words[i].find(prefix) == 0)
            matchedPrefix++;
        }
      }

      result.push_back(matchedPrefix);
    }

    return result;
  }

  vector<int> sumPrefixScoresBetter(vector<string> &words)
  {
    int n = words.size();

    unordered_map<string, int> freqMap;

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j <= words[i].length(); j++)
        freqMap[words[i].substr(0, j)]++;
    }

    vector<int> result;

    for (int i = 0; i < n; i++)
    {
      int matchedCount = 0;

      for (int j = 1; j <= words[i].length(); j++)
        matchedCount += freqMap[words[i].substr(0, j)];

      result.push_back(matchedCount);
    }

    return result;
  }

  void insert(string &word, trieNode *root)
  {
    trieNode *crawl = root;

    for (char &ch : word)
    {
      int index = ch - 'a';

      if (!crawl->children[index])
        crawl->children[index] = new trieNode();

      crawl->children[index]->freq += 1;

      crawl = crawl->children[index];
    }
  }

  int getScore(string &word, trieNode *root)
  {
    trieNode *crawl = root;

    int score = 0;

    for (char &ch : word)
    {
      int index = ch - 'a';

      score += crawl->children[index]->freq;

      crawl = crawl->children[index];
    }

    return score;
  }

  vector<int> sumPrefixScoresOptimal(vector<string> &words)
  {
    trieNode *root = new trieNode();

    for (string &word : words)
      insert(word, root);

    vector<int> result;

    for (string &word : words)
      result.push_back(getScore(word, root));

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> words = {"abc", "ab", "bc", "b"};

  auto ans = sol.sumPrefixScoresBrute(words);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.sumPrefixScoresBetter(words);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.sumPrefixScoresOptimal(words);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}