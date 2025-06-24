#include <bits/stdc++.h>
using namespace std;

class CustomStackBrute
{
  vector<int> stackVector;
  int top, stackSize;

public:
  CustomStackBrute(int maxSize)
  {
    top = -1;
    stackSize = maxSize;

    stackVector.resize(maxSize);
  }

  void push(int x)
  {
    if (top == stackSize - 1)
      return;

    stackVector[++top] = x;
  }

  int pop()
  {
    if (top == -1)
      return -1;

    return stackVector[top--];
  }

  void increment(int k, int val)
  {
    if (top == -1)
      return;

    for (int i = 0; i < min(k, stackSize); i++)
      stackVector[i] += val;
  }
};

class CustomStackoptimal
{
  vector<int> stackVector, incrementVector;
  int top, stackSize;

public:
  CustomStackoptimal(int maxSize)
  {
    top = -1;
    stackSize = maxSize;

    stackVector.resize(maxSize);
    incrementVector.resize(maxSize, 0);
  }

  void push(int x)
  {
    if (top == stackSize - 1)
      return;

    stackVector[++top] = x;
  }

  int pop()
  {
    if (top == -1)
      return -1;

    int incrementValue = incrementVector[top];

    incrementVector[top] = 0;

    if (top > 0)
      incrementVector[top - 1] += incrementValue;

    return stackVector[top--] + incrementValue;
  }

  void increment(int k, int val)
  {
    if (top == -1)
      return;

    incrementVector[min(k - 1, top)] += val;
  }
};

int main()
{
  return 0;
}