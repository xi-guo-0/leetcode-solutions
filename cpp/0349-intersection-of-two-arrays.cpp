class Solution {
public:
  vector<int> intersection(const vector<int> &nums1, const vector<int> &nums2) {
    unordered_set<int> s(nums1.begin(), nums1.end());
    vector<int> res;
    for (const int i : nums2)
      if (s.count(i)) {
        res.push_back(i);
        s.erase(i);
      }
    return res;
  }
};
