#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  static bool compare(int a, int b)
  {
    string str_a = to_string(a);
    string str_b = to_string(b);

    return str_a + str_b > str_b + str_a;
  }

  string largestNumber(vector<int> &nums)
  {
    sort(nums.begin(), nums.end(), compare);

    if (nums[0] == 0)
      return "0";

    string result = "";

    for (int num : nums)
      result += to_string(num);

    return result;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {3, 30, 34, 5, 9};

  cout << sol.largestNumber(nums);

  return 0;
}