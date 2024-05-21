#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename Key, typename Value>
std::ostream &operator<<(std::ostream &os,
                         const std::unordered_map<Key, Value> &map) {
  os << "{";
  for (const auto &pair : map) {
    os << pair.first << ": " << pair.second << ", ";
  }
  os << "}";
  return os;
}

class Solution {
public:
  int leastBricks(vector<vector<int>> &wall) {
    unordered_map<size_t, size_t> dict;
    for (const auto &row : wall) {
      size_t s = row[0];
      for (size_t i = 1; i < row.size(); ++i) {
        dict[s] += 1;
        s += row[i];
      }
    }

    size_t max_value = 0;

    for (const auto &p : dict) {
      max_value = max(max_value, p.second);
    }

    return wall.size() - max_value;
  }
};

int main() {
  Solution solution;
  vector<vector<int>> wall{{1, 2, 2, 1}, {3, 1, 2}, {1, 3, 2},
                           {2, 4},       {3, 1, 2}, {1, 3, 1, 1}};
  solution.leastBricks(wall);
  return 0;
}
