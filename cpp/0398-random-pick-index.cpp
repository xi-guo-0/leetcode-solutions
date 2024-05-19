#include <random>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  Solution(vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int x = nums[i];
      if (map.find(x) == map.end()) {
        map[x] = vector<int>();
      }
      map[x].push_back(i);
    }
    r = mt19937(7);
  }

  int pick(int target) {
    int ans = 0;
    if (map[target].size() == 1) {
      ans = map[target][0];
    } else {
      uniform_int_distribution<int> dist(0, map[target].size() - 1);
      int t = dist(r);
      ans = map[target][t];
    }
    return ans;
  }

private:
  unordered_map<int, vector<int>> map;
  mt19937 r;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
