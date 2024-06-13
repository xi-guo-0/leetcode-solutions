#include <algorithm>
#include <cmath>
#include <numeric>
#include <ranges>
#include <vector>

using namespace std;

int abs_diff(int a, int b) { return abs(a - b); }

class Solution {
public:
  int minMovesToSeat(vector<int> &seats, vector<int> &students) {
    ranges::sort(seats);
    ranges::sort(students);
    auto zipped_view =
        views::iota(0, (int)seats.size()) | views::transform([&](int i) {
          return pair{seats[i], students[i]};
        });
    return accumulate(ranges::begin(zipped_view), ranges::end(zipped_view), 0,
                      [&](int sum, const auto &pair) {
                        return sum + abs_diff(pair.first, pair.second);
                      });
  }
};

int main() { return 0; }
