#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void getsWordVector(vector<string> &wordsVector, string sentence)
  {
    stringstream sentenceStream(sentence);
    string token;

    while (sentenceStream >> token)
      wordsVector.push_back(token);
  }

  bool findSimilarity(string &sentence1, string &sentence2)
  {
    vector<string> wordsVector1, wordsVector2;

    getsWordVector(wordsVector1, sentence1);
    getsWordVector(wordsVector2, sentence2);

    int l1 = wordsVector1.size();
    int l2 = wordsVector2.size();

    int i = 0, j = l1 - 1;
    int k = 0, l = l2 - 1;

    while (i < l1 && k < l2 && wordsVector1[i] == wordsVector2[k])
    {
      i++;
      k++;
    }

    while (l >= k && wordsVector1[j] == wordsVector2[l])
    {
      j--;
      l--;
    }

    return l < k;
  }

  bool areSentencesSimilar(string sentence1, string sentence2)
  {
    if (sentence1 == sentence2)
      return true;

    if (sentence1.length() < sentence2.length())
      return findSimilarity(sentence2, sentence1);

    return findSimilarity(sentence1, sentence2);
  }

  void getsWordDeque(deque<string> &wordsDeque, string sentence)
  {
    stringstream sentenceStream(sentence);
    string token;

    while (sentenceStream >> token)
      wordsDeque.push_back(token);
  }

  bool findSimilarityDeque(string &sentence1, string &sentence2)
  {
    deque<string> wordsDeque1, wordsDeque2;

    getsWordDeque(wordsDeque1, sentence1);
    getsWordDeque(wordsDeque2, sentence2);

    while (!wordsDeque1.empty() && !wordsDeque2.empty() && wordsDeque1.front() == wordsDeque2.front())
    {
      wordsDeque1.pop_front();
      wordsDeque2.pop_front();
    }

    while (!wordsDeque2.empty() && wordsDeque1.back() == wordsDeque2.back())
    {
      wordsDeque1.pop_back();
      wordsDeque2.pop_back();
    }

    return wordsDeque2.empty();
  }

  bool areSentencesSimilarDeque(string sentence1, string sentence2)
  {
    if (sentence1 == sentence2)
      return true;

    if (sentence1.length() < sentence2.length())
      return findSimilarityDeque(sentence2, sentence1);

    return findSimilarityDeque(sentence1, sentence2);
  }
};

int main()
{
  Solution sol;
  string s1 = "My name is Haley Comets", s2 = "Comets";

  cout << sol.areSentencesSimilar(s1, s2) << endl;
  cout << sol.areSentencesSimilarDeque(s1, s2) << endl;

  return 0;
}