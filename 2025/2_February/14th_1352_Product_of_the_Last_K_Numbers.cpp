#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbersBrute
{
  vector<int> nums;

public:
  ProductOfNumbersBrute() {}

  void add(int num) { nums.push_back(num); }

  int getProduct(int k)
  {
    int n = nums.size();
    int product = 1;

    for (int i = n - 1; i >= n - k; i--)
      product *= nums[i];

    return product;
  }
};

class ProductOfNumbersOptimal
{
  vector<int> nums;
  int n = 0;

public:
  ProductOfNumbersOptimal() {}

  void add(int num)
  {
    if (nums.empty())
      nums.push_back(num);
    else
      nums.push_back(num * nums[n - 1]);

    n++;

    if (num == 0)
    {
      nums = {};
      n = 0;
    }
  }

  int getProduct(int k)
  {
    if (k > n)
      return 0;

    else if (k == n)
      return nums[n - 1];

    return nums[n - 1] / nums[n - k - 1];
  }
};

int main()
{
  return 0;
}