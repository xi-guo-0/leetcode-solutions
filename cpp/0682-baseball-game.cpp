#include <string>
#include <vector>

class Solution {
public:
  int calPoints(std::vector<std::string> &ops) {
    if (ops.empty()) {
      return 0;
    }

    int sum = 0;
    std::vector<int> nums(ops.size(), 0);
    int index = 0;

    for (const auto &op : ops) {
      char c = op[0];
      switch (c) {
      case '+':
        nums[index] = nums[index - 1] + nums[index - 2];
        index++;
        break;
      case 'D':
        nums[index] = nums[index - 1] * 2;
        index++;
        break;
      case 'C':
        --index;
        nums[index] = 0;
        break;
      default:
        nums[index] = std::stoi(op);
        index++;
        break;
      }
    }

    for (int ele : nums) {
      sum += ele;
    }

    return sum;
  }
};
