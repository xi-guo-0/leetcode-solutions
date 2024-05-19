class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> result;
    for (auto i = nums1.begin(), j = nums2.begin();
         i != nums1.end() || j != nums2.end();) {
      int a = i != nums1.end() ? *i : INT_MAX;
      int b = j != nums2.end() ? *j : INT_MAX;
      if (a == b) {
        result.push_back(a);
        i++;
        j++;
      } else if (a < b) {
        i++;
      } else {
        j++;
      }
    }
    return result;
  }
};
