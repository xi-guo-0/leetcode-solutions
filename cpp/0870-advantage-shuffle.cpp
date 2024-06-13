#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.empty() || nums1.size() != nums2.size())
      return nums1;
    vector<int> ans(nums1.size());
    vector<pair<int, int>> b_with_index;
    for (int i = 0; i < nums2.size(); ++i)
      b_with_index.push_back({nums2[i], i});
    sort(nums1.begin(), nums1.end());
    sort(b_with_index.begin(), b_with_index.end());
    auto it = b_with_index.begin();
    auto rit = b_with_index.rbegin();
    for (int i = 0; i < nums1.size(); ++i) {
      if (it->first < nums1[i]) {
        ans[it->second] = nums1[i];
        ++it;
      } else {
        ans[rit->second] = nums1[i];
        ++rit;
      }
    }
    return ans;
  }
};

int main() { return 0; }
