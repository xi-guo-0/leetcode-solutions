#include <vector>

using namespace std;

class Solution {
public:
  bool validMountainArray(const vector<int> &arr) {
    if (arr.size() < 3) {
      return false;
    }
    auto it = next(arr.cbegin());
    while (it != arr.cend() && *prev(it) < *it)
      it++;

    if (it == next(arr.cbegin()) || it == arr.cend()) {
      return false;
    }
    while (it != arr.cend() && *prev(it) > *it)
      it++;
    return it == arr.cend();
  }
};

int main() { return 0; }
