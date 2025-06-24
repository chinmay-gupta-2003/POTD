#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void getMinChar(char ch, vector<vector<char>> &adj, vector<int> &vis, char &minChar)
  {
    vis[ch - 'a'] = 1;
    minChar = min(minChar, ch);

    for (char &adjNode : adj[ch - 'a'])
    {
      if (!vis[adjNode - 'a'])
        getMinChar(adjNode, adj, vis, minChar);
    }
  }

  string smallestEquivalentString(string s1, string s2, string baseStr)
  {
    int n = s1.length();

    vector<vector<char>> adj(26);

    for (int i = 0; i < n; i++)
    {
      char u = s1[i], v = s2[i];

      adj[u - 'a'].push_back(v);
      adj[v - 'a'].push_back(u);
    }

    for (int i = 0; i < baseStr.size(); i++)
    {
      vector<int> vis(26, 0);

      char minChar = baseStr[i];

      getMinChar(baseStr[i], adj, vis, minChar);

      baseStr[i] = minChar;
    }

    return baseStr;
  }
};

int main()
{
  Solution sol;
  string s1 = "parker", s2 = "morris", baseStr = "parser";

  cout << sol.smallestEquivalentString(s1, s2, baseStr) << endl;

  return 0;
}