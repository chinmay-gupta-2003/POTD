#include <bits/stdc++.h>
using namespace std;

class AllOne
{
private:
  struct Node
  {
    int count;
    unordered_set<string> keys;

    Node *prev;
    Node *next;

    Node(int cnt)
    {
      count = cnt;

      prev = nullptr;
      next = nullptr;
    }
  };

  unordered_map<string, Node *> nodeMap;

  Node *head;
  Node *tail;

  void addNewNode(Node *prevNode, int count)
  {
    Node *newNode = new Node(count);

    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (newNode->next)
      newNode->next->prev = newNode;

    prevNode->next = newNode;

    if (tail == prevNode)
      tail = newNode;
  }

  void removeNode(Node *node)
  {
    node->prev->next = node->next;

    if (node->next)
      node->next->prev = node->prev;

    if (tail == node)
      tail = node->prev;

    delete (node);
  }

public:
  AllOne()
  {
    head = new Node(0);
    tail = head;
  }

  void inc(string key)
  {
    if (nodeMap.find(key) == nodeMap.end())
    {
      if (head->next == nullptr || head->next->count != 1)
        addNewNode(head, 1);

      head->next->keys.insert(key);
      nodeMap[key] = head->next;
    }
    else
    {
      Node *currNode = nodeMap[key];

      currNode->keys.erase(key);

      if (currNode->next == nullptr || currNode->next->count != currNode->count + 1)
        addNewNode(currNode, currNode->count + 1);

      currNode->next->keys.insert(key);

      nodeMap[key] = currNode->next;

      if (currNode->keys.empty())
        removeNode(currNode);
    }
  }

  void dec(string key)
  {
    Node *currNode = nodeMap[key];

    currNode->keys.erase(key);

    if (currNode->count == 1)
      nodeMap.erase(key);
    else
    {
      if (currNode->prev == head || currNode->prev->count != currNode->count - 1)
        addNewNode(currNode->prev, currNode->count - 1);

      currNode->prev->keys.insert(key);

      nodeMap[key] = currNode->prev;
    }

    if (currNode->keys.empty())
      removeNode(currNode);
  }

  string getMaxKey()
  {
    if (tail == head)
      return "";

    return *tail->keys.begin();
  }

  string getMinKey()
  {
    if (head->next == nullptr)
      return "";

    return *head->next->keys.begin();
  }
};

int main()
{
  return 0;
}