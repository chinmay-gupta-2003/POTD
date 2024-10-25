#include <bits/stdc++.h>
using namespace std;

void print(vector<string> &folder)
{
  for (auto it : folder)
    cout << it << " ";

  cout << endl;
}

class Solution
{
public:
  vector<string> removeSubfoldersBrute(vector<string> &folder)
  {
    int n = folder.size();

    unordered_set<string> s;
    vector<string> parentFolders;

    for (auto it : folder)
      s.insert(it);

    for (int i = 0; i < n; i++)
    {
      int l1 = folder[i].length();

      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;

        int l2 = folder[j].length();

        if ((l2 > l1) && folder[j].substr(0, l1) == folder[i] && folder[j][l1] == '/')
          s.erase(folder[j]);
      }
    }

    for (auto it : s)
      parentFolders.push_back(it);

    return parentFolders;
  }

  vector<string> removeSubfoldersBetter(vector<string> &folder)
  {
    int n = folder.size();

    unordered_set<string> s;
    vector<string> parentFolders;

    for (auto it : folder)
      s.insert(it);

    for (int i = 0; i < n; i++)
    {
      bool flag = false;

      for (int j = folder[i].length() - 1; j > 1; j--)
      {
        if (folder[i][j] == '/')
        {
          string subStr = folder[i].substr(0, j);

          if (s.find(subStr) != s.end())
          {
            flag = true;
            break;
          }
        }
      }

      if (!flag)
        parentFolders.push_back(folder[i]);
    }

    return parentFolders;
  }

  vector<string> removeSubfoldersOptimal(vector<string> &folder)
  {
    int n = folder.size();

    sort(folder.begin(), folder.end());

    vector<string> parentFolders;
    parentFolders.push_back(folder[0]);

    for (int i = 1; i < n; i++)
    {
      string parent = parentFolders.back() + "/";

      if (folder[i].find(parent) != 0)
        parentFolders.push_back(folder[i]);
    }

    return parentFolders;
  }
};

int main()
{
  Solution sol;
  vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  vector<string> ans;

  ans = sol.removeSubfoldersBrute(folder);
  print(ans);

  ans = sol.removeSubfoldersBetter(folder);
  print(ans);

  ans = sol.removeSubfoldersOptimal(folder);
  print(ans);

  return 0;
}