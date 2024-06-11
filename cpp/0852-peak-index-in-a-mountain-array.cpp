#include <vector>

using namespace std;

class Solution {
public:
  int peakIndexInMountainArray(vector<int> &A) {
    A.insert(A.begin(), -1);
    A.push_back(-1);
    int l = 1, r = A.size() - 2, mid = 0;
    while (l < r) {
      mid = l + (r - l) / 2;
      if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
        break;
      else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1])
        l = mid;
      else
        r = mid;
    }
    return mid - 1;
  }
};

int main() { return 0; }
