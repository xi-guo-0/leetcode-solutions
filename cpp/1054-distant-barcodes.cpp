#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes) {
    unordered_map<int, int> freq;
    for (auto barcode : barcodes) {
      ++freq[barcode];
    }

    auto cmp = [&freq](int a, int b) { return freq[a] < freq[b]; };
    priority_queue<int, vector<int>, decltype(cmp)> max_heap(cmp);

    for (const auto &[barcode, _] : freq) {
      max_heap.push(barcode);
    }

    vector<int> result;
    int prev = -1;

    while (!max_heap.empty()) {
      int current = max_heap.top();
      max_heap.pop();
      result.push_back(current);
      --freq[current];

      if (prev != -1 && freq[prev] > 0) {
        max_heap.push(prev);
      }

      prev = current;
    }

    return result;
  }
};

int main() { return 0; }