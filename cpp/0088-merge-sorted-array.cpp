class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> res;
    for (int i = 0, j = 0; i < m || j < n;) {
      int a = i < m ? nums1[i] : INT_MAX;
      int b = j < n ? nums2[j] : INT_MAX;
      if (a < b) {
        res.push_back(a);
        i++;
      } else {
        res.push_back(b);
        j++;
      }
    }
    int i = 0;
    for (auto num : res) {
      nums1[i++] = num;
    }
  }
};
