#include <cstddef>
#include <vector>

using namespace std;

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int n = citations.size();
    return binary_search(citations, 0, n - 1, n);
  }

  int binary_search(vector<int> &citations, int start, int end, int n) {
    if (start > end)
      return n - start;

    int mid = start + (end - start) / 2;
    if (citations[mid] < n - mid) {
      return binary_search(citations, mid + 1, end, n);
    } else {
      return binary_search(citations, start, mid - 1, n);
    }
  }
};

int main() { return 0; }
