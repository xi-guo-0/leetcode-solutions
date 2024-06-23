#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  bool canReorderDoubled(std::vector<int> &arr) {

    std::unordered_map<int, int> freq;
    for (int num : arr) {
      freq[num]++;
    }

    std::sort(arr.begin(), arr.end(),
              [](int a, int b) { return std::abs(a) < std::abs(b); });

    for (int num : arr) {
      if (freq[num] > 0) {
        if (freq[2 * num] <= 0) {
          return false;
        }
        freq[num]--;
        freq[2 * num]--;
      }
    }

    return true;
  }
};

int main() { return 0; }
