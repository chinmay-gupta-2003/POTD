#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool checkIfExist(vector<int> &arr)
  {
    unordered_set<int> st;

    for (auto it : arr)
    {
      if (st.find(2 * it) != st.end())
        return true;

      else if (it % 2 == 0 && (st.find(it / 2) != st.end()))
        return true;

      st.insert(it);
    }

    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {10, 2, 5, 1};

  cout << sol.checkIfExist(arr);

  return 0;
}