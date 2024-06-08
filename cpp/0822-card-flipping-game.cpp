#include <cstddef>
#include <limits>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int flipgame(vector<int> &fronts, vector<int> &backs) {
    unordered_set<int> single_face_numbers;
    for (size_t i = 0; i < fronts.size(); ++i) {
      if (fronts[i] == backs[i]) {
        single_face_numbers.insert(fronts[i]);
      }
    }
    int ans = numeric_limits<int>::max();
    for (int i : fronts) {
      if (!single_face_numbers.count(i)) {
        ans = min(ans, i);
      }
    }
    for (int i : backs) {
      if (!single_face_numbers.count(i)) {
        ans = min(ans, i);
      }
    }
    return ans == numeric_limits<int>::max() ? 0 : ans;
  }
};

int main() { return 0; }
