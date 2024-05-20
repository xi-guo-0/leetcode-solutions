#include <vector>

using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> result(nums1.size(), -1);

    for (int i = 0; i < nums1.size(); i++) {
      for (int j = 0; j < nums2.size(); j++) {
        if (nums1[i] == nums2[j]) {
          int num = -1;
          for (int k = j + 1; k < nums2.size(); k++) {
            if (nums2[k] > nums2[j]) {
              num = nums2[k];
              break;
            }
          }
          result[i] = num;
          break;
        }
      }
    }

    return result;
  }
};
