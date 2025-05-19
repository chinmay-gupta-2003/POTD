#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string triangleType(vector<int> &nums)
  {
    int sideOne = nums[0], sideTwo = nums[1], sideThree = nums[2];

    if (sideOne + sideTwo <= sideThree || sideOne + sideThree <= sideTwo || sideTwo + sideThree <= sideOne)
      return "none";

    if (sideOne == sideTwo && sideOne == sideThree)
      return "equilateral";

    if (sideOne == sideTwo || sideOne == sideThree || sideTwo == sideThree)
      return "isosceles";

    return "scalene";
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 4};

  cout << sol.triangleType(nums);

  return 0;
}