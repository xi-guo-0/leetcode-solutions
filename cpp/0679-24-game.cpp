#include <cmath>
#include <functional>
#include <vector>

class Solution {
private:
  static constexpr int TARGET = 24;
  static constexpr double EPSILON = 1e-6;
  static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

public:
  bool judgePoint24(std::vector<int> &nums) {
    std::vector<double> list(nums.begin(), nums.end());
    return solve(list);
  }

  bool solve(std::vector<double> &list) {
    if (list.size() == 1)
      return std::abs(list[0] - TARGET) < EPSILON;
    return [&] {
      for (size_t i = 0; i < list.size(); ++i) {
        for (size_t j = 0; j < list.size(); ++j) {
          if (i != j) {
            std::vector<double> list2;
            for (size_t k = 0; k < list.size(); ++k)
              if (k != i && k != j)
                list2.push_back(list[k]);
            for (auto op : {ADD, MULTIPLY, SUBTRACT, DIVIDE}) {
              if (op < 2 && i > j)
                continue;
              if (op == ADD)
                list2.push_back(list[i] + list[j]);
              else if (op == MULTIPLY)
                list2.push_back(list[i] * list[j]);
              else if (op == SUBTRACT)
                list2.push_back(list[i] - list[j]);
              else if (std::abs(list[j]) > EPSILON)
                list2.push_back(list[i] / list[j]);
              if (solve(list2))
                return true;
              list2.pop_back();
            }
          }
        }
      }
      return false;
    }();
  }
};
