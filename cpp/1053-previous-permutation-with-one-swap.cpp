#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> prevPermOpt1(vector<int> &arr) {
    int n = arr.size();
    int i = n - 2;
    while (0 <= i && arr[i] <= arr[i + 1]) {
      --i;
    }
    if (i < 0) {
      return arr;
    }
    int j = n - 1;
    while (arr[i] <= arr[j] || arr[j - 1] == arr[j]) {
      --j;
    }
    swap(arr[i], arr[j]);
    return arr;
  }
};

int main() { return 0; }