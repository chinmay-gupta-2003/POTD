#include <bits/stdc++.h>
using namespace std;

class NumberContainersBrute
{
public:
  unordered_map<int, set<int>> numIndicesMap;
  unordered_map<int, int> indexNumMap;

  NumberContainersBrute() {}

  void change(int index, int number)
  {
    if (indexNumMap.count(index))
    {
      int prevNumber = indexNumMap[index];

      numIndicesMap[prevNumber].erase(index);

      if (numIndicesMap[prevNumber].size() == 0)
        numIndicesMap.erase(prevNumber);
    }

    indexNumMap[index] = number;
    numIndicesMap[number].insert(index);
  }

  int find(int number)
  {
    int result = -1;

    if (numIndicesMap.count(number))
      result = *numIndicesMap[number].begin();

    return result;
  }
};

int main()
{
  return 0;
}