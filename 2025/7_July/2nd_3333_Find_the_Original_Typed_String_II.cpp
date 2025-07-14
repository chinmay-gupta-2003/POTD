#include <bits/stdc++.h>
using namespace std;

class Solution
{
  int MOD = 1e9 + 7;

public:
  int solveBrute(int idx, int count, vector<int> &freqMap, int k)
  {
    if (idx >= freqMap.size())
    {
      if (count < k)
        return 1;

      return 0;
    }

    long long result = 0;

    for (int freq = 1; freq <= freqMap[idx]; freq++)
    {
      if (count + freq < k)
        result = (result + solveBrute(idx + 1, count + freq, freqMap, k)) % MOD;
      else
        break;
    }

    return result;
  }

  int possibleStringCountBrute(string word, int k)
  {
    if (k > word.size())
      return 0;

    int count = 1;
    vector<int> freqMap;

    for (int i = 1; i < word.size(); i++)
    {
      if (word[i] == word[i - 1])
        count++;
      else
      {
        freqMap.push_back(count);
        count = 1;
      }
    }

    freqMap.push_back(count);

    int allCombinations = 1;

    for (int freq : freqMap)
    {
      allCombinations = (allCombinations * freq) % MOD;
    }

    if (freqMap.size() >= k)
      return allCombinations;

    int invalidCombinations = solveBrute(0, 0, freqMap, k);

    return (allCombinations - invalidCombinations + MOD) % MOD;
  }

  int solveMemoize(int idx, int count, vector<int> &freqMap, int k, vector<vector<int>> &dp)
  {
    if (idx >= freqMap.size())
    {
      if (count < k)
        return 1;

      return 0;
    }

    if (dp[idx][count] != -1)
      return dp[idx][count];

    long long result = 0;

    for (int freq = 1; freq <= freqMap[idx]; freq++)
    {
      if (count + freq < k)
        result = (result + solveMemoize(idx + 1, count + freq, freqMap, k, dp)) % MOD;
      else
        break;
    }

    return dp[idx][count] = result;
  }

  int possibleStringCountMemoize(string word, int k)
  {
    int n = word.size();

    if (k > n)
      return 0;

    int count = 1;
    vector<int> freqMap;

    for (int i = 1; i < n; i++)
    {
      if (word[i] == word[i - 1])
        count++;
      else
      {
        freqMap.push_back(count);
        count = 1;
      }
    }

    freqMap.push_back(count);

    long long allCombinations = 1;

    for (int freq : freqMap)
    {
      allCombinations = (allCombinations * freq) % MOD;
    }

    if (freqMap.size() >= k)
      return allCombinations;

    vector<vector<int>> dp(word.size(), vector<int>(k, -1));

    int invalidCombinations = solveMemoize(0, 0, freqMap, k, dp);

    return (allCombinations - invalidCombinations + MOD) % MOD;
  }

  int possibleStringCountBottomUp(string word, int k)
  {
    int n = word.size();

    if (k > n)
      return 0;

    int count = 1;
    vector<int> freqMap;

    for (int i = 1; i < n; i++)
    {
      if (word[i] == word[i - 1])
        count++;
      else
      {
        freqMap.push_back(count);
        count = 1;
      }
    }

    freqMap.push_back(count);

    long long allCombinations = 1;

    for (int freq : freqMap)
    {
      allCombinations = (allCombinations * freq) % MOD;
    }

    if (freqMap.size() >= k)
      return allCombinations;

    int m = freqMap.size();

    vector<vector<int>> dp(m + 1, vector<int>(k, 0));

    for (int i = 0; i < k; i++)
    {
      dp[m][i] = 1;
    }

    for (int idx = m - 1; idx >= 0; idx--)
    {
      for (int count = 0; count < k; count++)
      {
        long long result = 0;

        for (int freq = 1; freq <= freqMap[idx]; freq++)
        {
          if (count + freq < k)
            result = (result + dp[idx + 1][count + freq]) % MOD;
          else
            break;
        }

        dp[idx][count] = result;
      }
    }

    return (allCombinations - dp[0][0] + MOD) % MOD;
  }

  int possibleStringCountOptimal(string word, int k)
  {
    int n = word.size();

    if (k > n)
      return 0;

    int count = 1;
    vector<int> freqMap;

    for (int i = 1; i < n; i++)
    {
      if (word[i] == word[i - 1])
        count++;
      else
      {
        freqMap.push_back(count);
        count = 1;
      }
    }

    freqMap.push_back(count);

    long long allCombinations = 1;

    for (int freq : freqMap)
    {
      allCombinations = (allCombinations * freq) % MOD;
    }

    if (freqMap.size() >= k)
      return allCombinations;

    int m = freqMap.size();

    vector<vector<int>> dp(m + 1, vector<int>(k, 0));

    for (int i = 0; i < k; i++)
    {
      dp[m][i] = 1;
    }

    for (int idx = m - 1; idx >= 0; idx--)
    {
      vector<int> prefixSum(k + 1, 0);

      for (int h = 1; h <= k; h++)
      {
        prefixSum[h] = (prefixSum[h - 1] + dp[idx + 1][h - 1]) % MOD;
      }

      for (int count = 0; count < k; count++)
      {
        long long result = 0;

        int l = count + 1;
        int r = count + freqMap[idx];

        if (r + 1 > k)
          r = k - 1;

        if (l <= r)
          dp[idx][count] = (prefixSum[r + 1] - prefixSum[l] + MOD) % MOD;
      }
    }

    return (allCombinations - dp[0][0] + MOD) % MOD;
  }
};

int main()
{
  Solution sol;
  int k = 7;
  string word = "aabbccdd";

  cout << sol.possibleStringCountBrute(word, k) << endl;
  cout << sol.possibleStringCountMemoize(word, k) << endl;
  cout << sol.possibleStringCountBottomUp(word, k) << endl;
  cout << sol.possibleStringCountOptimal(word, k) << endl;

  return 0;
}