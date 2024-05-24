class Solution {
public:
  vector<int> findClosestElements(const vector<int> &arr, const int k,
                                  const int x) {
    if (x <= arr.front()) {
      return vector<int>(arr.begin(), next(arr.begin(), k));
    } else if (arr.back() <= x) {
      return vector<int>(prev(arr.end(), k), arr.end());
    }
    vector<int> ans;
    auto q = lower_bound(arr.begin(), arr.end(), x);
    auto p = make_reverse_iterator(q);
    for (int i = 0; i < k; ++i) {
      const int a = p != arr.rend() ? x - *p : numeric_limits<int>::max();
      const int b = q != arr.end() ? *q - x : numeric_limits<int>::max();
      if (a <= b) {
        ans.push_back(*p);
        ++p;
      } else {
        ans.push_back(*q);
        ++q;
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
