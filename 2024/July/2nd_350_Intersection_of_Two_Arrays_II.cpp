#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int n1 = nums1.size(), n2 = nums2.size();
    int i = 0, j = 0;

    vector<int> result;

    while (i < n1 && j < n2)
    {
      if (nums1[i] == nums2[j])
      {
        result.push_back(nums1[i]);

        i++;
        j++;
      }
      else if (nums1[i] < nums2[j])
        i++;
      else
        j++;
    }

    return result;
  }
};

int main()
{
  Solution sol;

  vector<int> nums1 = {1, 2, 2, 1}, nums2 = {1, 2, 2, 3};

  auto ans = sol.intersect(nums1, nums2);

  for (auto it : ans)
    cout << it << " ";

  return 0;
}