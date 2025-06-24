#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxWidthRampBrute(vector<int> &nums)
  {
    int n = nums.size();
    int maxRampWidth = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      int k = i;

      for (int j = i + 1; j < n; j++)
      {
        if (nums[j] >= nums[i])
          k = j;
      }

      maxRampWidth = max(maxRampWidth, k - i);
    }

    return maxRampWidth;
  }

  int maxWidthRampOptimal(vector<int> &nums)
  {
    int n = nums.size();
    stack<int> st;
    int maxRampWidth = 0;

    for (int i = 0; i < n; i++)
    {
      if (st.empty() || nums[st.top()] >= nums[i])
        st.push(i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
      while (!st.empty() && nums[i] >= nums[st.top()])
      {
        maxRampWidth = max(maxRampWidth, i - st.top());
        st.pop();
      }
    }

    return maxRampWidth;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {6, 0, 8, 2, 1, 5};

  cout << sol.maxWidthRampBrute(arr) << endl;
  cout << sol.maxWidthRampOptimal(arr) << endl;

  return 0;
}