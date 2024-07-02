#include <limits>
#include <numeric>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    ranges::sort(nums1);
    ranges::sort(nums2);
    vector<int> result;
    for (auto i = nums1.begin(), j = nums2.begin();
         i != nums1.end() || j != nums2.end();) {
      int a = i != nums1.end() ? *i : numeric_limits<int>::max();
      int b = j != nums2.end() ? *j : numeric_limits<int>::max();
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

int main() { return 0; }
