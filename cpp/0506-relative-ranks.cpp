#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int> &nums) {
    unordered_map<int, string> map;
    vector<int> order = nums;
    vector<string> result(nums.size());

    sort(order.begin(), order.end(), greater<int>());

    if (!nums.empty())
      map[order[0]] = "Gold Medal";
    if (order.size() > 1)
      map[order[1]] = "Silver Medal";
    if (order.size() > 2)
      map[order[2]] = "Bronze Medal";

    for (size_t i = 3; i < order.size(); i++) {
      map[order[i]] = to_string(i + 1);
    }

    for (size_t i = 0; i < nums.size(); i++) {
      result[i] = map[nums[i]];
    }

    return result;
  }
};
