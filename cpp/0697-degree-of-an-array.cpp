#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int findShortestSubArray(std::vector<int> &nums) {
    std::unordered_map<int, int> map;
    for (int num : nums) {
      if (map.find(num) == map.end()) {
        map[num] = 1;
      } else {
        map[num]++;
      }
    }

    int maximum = INT_MIN;
    for (const auto &pair : map) {
      maximum = std::max(maximum, pair.second);
    }

    std::vector<int> might;
    for (const auto &pair : map) {
      if (pair.second == maximum) {
        might.push_back(pair.first);
      }
    }

    int result = nums.size();
    for (int i = 0; i < might.size(); i++) {
      int begin = 0;
      while (nums[begin] != might[i]) {
        begin++;
      }
      int end = nums.size() - 1;
      while (nums[end] != might[i]) {
        end--;
      }
      result = std::min(result, end - begin + 1);
    }

    return result;
  }
};
