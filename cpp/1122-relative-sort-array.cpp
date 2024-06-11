#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, const vector<int> &arr2) {
    int index = 0;
    map<int, int> order;
    int mid = 0;
    for (auto n : arr2)
      order.insert({n, index++});
    for (auto n : arr1)
      if (order.find(n) == order.end())
        order.insert({n, index});
      else if (order[n] != index)
        mid++;
    sort(arr1.begin(), arr1.end(),
         [&order](int a, int b) { return order[a] < order[b]; });
    sort(next(arr1.begin(), mid), arr1.end());
    return arr1;
  }
};

int main() { return 0; }
