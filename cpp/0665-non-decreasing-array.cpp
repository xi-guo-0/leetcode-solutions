class Solution {
public:
  bool checkPossibility(vector<int> &nums) {
    nums.insert(nums.begin(), INT_MIN);
    nums.push_back(INT_MAX);
    auto it = adjacent_find(nums.begin(), nums.end(),
                            [](const int a, const int b) { return a > b; });
    if (it == nums.end()) {
      return true;
    }
    int tmp = *it;
    *it = *prev(it);
    if (adjacent_find(nums.begin(), nums.end(), [](const int a, const int b) {
          return a > b;
        }) == nums.end()) {
      return true;
    }
    *it = *next(it) = tmp;
    if (adjacent_find(nums.begin(), nums.end(), [](const int a, const int b) {
          return a > b;
        }) == nums.end()) {
      return true;
    }
    return false;
  }
};
