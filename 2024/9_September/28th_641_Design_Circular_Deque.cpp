#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
public:
  vector<int> deque;
  int front, rear, size, k;

  MyCircularDeque(int k)
  {
    deque.resize(k);

    this->k = k;
    front = 0;
    rear = k - 1;
    size = 0;
  }

  bool insertFront(int value)
  {
    if (size == k)
      return false;

    front = (front - 1 + k) % k;
    deque[front] = value;

    size++;

    return true;
  }

  bool insertLast(int value)
  {
    if (size == k)
      return false;

    rear = (rear + 1) % k;
    deque[rear] = value;

    size++;

    return true;
  }

  bool deleteFront()
  {
    if (size == 0)
      return false;

    front = (front + 1) % k;

    size--;

    return true;
  }

  bool deleteLast()
  {
    if (size == 0)
      return false;

    rear = (rear - 1 + k) % k;

    size--;

    return true;
  }

  int getFront()
  {
    if (size == 0)
      return -1;

    return deque[front];
  }

  int getRear()
  {
    if (size == 0)
      return -1;

    return deque[rear];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == k; }
};

int main()
{
  return 0;
}