#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxDistance(vector<int> &position, int m) {

    sort(position.begin(), position.end());

    int left = 1;
    int right = position.back() - position.front();

    int result = 0;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (canPlaceBalls(position, m, mid)) {
        result = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return result;
  }

private:
  bool canPlaceBalls(const vector<int> &position, int m, int distance) {
    int count = 1;
    int last_position = position[0];

    for (int i = 1; i < position.size(); ++i) {
      if (position[i] - last_position >= distance) {
        ++count;
        last_position = position[i];
        if (count == m) {
          return true;
        }
      }
    }

    return false;
  }
};

int main() { return 0; }
