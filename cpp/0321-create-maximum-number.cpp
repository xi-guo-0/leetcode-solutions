#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    vector<int> res(k, 0);
    for (int i = max(0, k - n); i <= min(k, m); ++i) {
      vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k - i));
      if (greater(candidate, res)) {
        res = std::move(candidate);
      }
    }
    return res;
  }

private:
  vector<int> maxArray(vector<int> &nums, int k) {
    vector<int> res;
    int to_pop = nums.size() - k;
    for (int num : nums) {
      while (to_pop && !res.empty() && res.back() < num) {
        res.pop_back();
        --to_pop;
      }
      res.push_back(num);
    }
    res.resize(k);
    return res;
  }

  vector<int> merge(vector<int> nums1, vector<int> nums2) {
    vector<int> res;
    while (!nums1.empty() || !nums2.empty()) {
      vector<int> &maxArray = greater(nums1, nums2) ? nums1 : nums2;
      res.push_back(maxArray[0]);
      maxArray.erase(maxArray.begin());
    }
    return res;
  }

  bool greater(const vector<int> &nums1, const vector<int> &nums2) {
    for (int i = 0; i < nums1.size() && i < nums2.size(); ++i) {
      if (nums1[i] > nums2[i])
        return true;
      if (nums1[i] < nums2[i])
        return false;
    }
    return nums1.size() > nums2.size();
  }
};

int main() {
  vector<int> nums1{3, 4, 6, 5};
  vector<int> nums2{9, 1, 2, 5, 8, 3};
  int k = 5;
  assert((Solution().maxNumber(nums1, nums2, k) == vector<int>{9, 8, 6, 5, 3}));
  return 0;
}
