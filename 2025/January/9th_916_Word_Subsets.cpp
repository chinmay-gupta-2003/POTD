#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> wordSubsetsBetter(vector<string> &words1, vector<string> &words2)
  {
    int n1 = words1.size(), n2 = words2.size();

    vector<unordered_map<char, int>> freqMapOne(n1), freqMapTwo(n2);

    unordered_map<char, int> maxFreqMap;

    for (int i = 0; i < n2; i++)
    {
      for (char ch : words2[i])
      {
        freqMapTwo[i][ch]++;

        maxFreqMap[ch] = max(maxFreqMap[ch], freqMapTwo[i][ch]);
      }
    }

    for (int i = 0; i < n1; i++)
    {
      for (char ch : words1[i])
        freqMapOne[i][ch]++;
    }

    vector<string> result;

    for (int i = 0; i < n1; i++)
    {
      bool flag = true;

      for (auto it : maxFreqMap)
      {
        if (freqMapOne[i][it.first] < it.second)
        {
          flag = false;
          break;
        }
      }

      if (flag)
        result.push_back(words1[i]);
    }

    return result;
  }

  bool checkSubset(vector<int> &freq, vector<int> &maxfreq)
  {
    for (int i = 0; i < 26; i++)
    {
      if (maxfreq[i] > freq[i])
        return false;
    }

    return true;
  }

  vector<string> wordSubsetsOptimal(vector<string> &words1, vector<string> &words2)
  {
    int n1 = words1.size(), n2 = words2.size();

    vector<int> maxFreq(26, 0);

    for (int i = 0; i < n2; i++)
    {
      vector<int> freq(26, 0);

      for (char ch : words2[i])
      {
        freq[ch - 'a']++;

        maxFreq[ch - 'a'] = max(maxFreq[ch - 'a'], freq[ch - 'a']);
      }
    }

    vector<string> result;

    for (int i = 0; i < n1; i++)
    {
      vector<int> freq(26, 0);

      for (char ch : words1[i])
        freq[ch - 'a']++;

      if (checkSubset(freq, maxFreq))
        result.push_back(words1[i]);
    }

    return result;
  }
};

int main()
{
  Solution sol;
  vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
  vector<string> words2 = {"l", "e"};

  auto ans = sol.wordSubsetsBetter(words1, words2);

  for (auto it : ans)
    cout << it << " ";

  cout << endl;

  ans = sol.wordSubsetsOptimal(words1, words2);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}