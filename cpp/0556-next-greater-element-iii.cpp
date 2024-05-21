class Solution {
public:
  int nextGreaterElement(int n) {
    vector<int> a = decode(n);
    if (next_permutation(begin(a), end(a))) {
      return code(a);
    }
    return -1;
  }

private:
  static constexpr int base = 10;

  vector<int> decode(int num) {
    vector<int> ans;
    while (0 < num) {
      ans.push_back(num % base);
      num /= base;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

  int code(vector<int> v) {
    long ans = 0;
    for (int i = 0; i < v.size(); ++i) {
      ans *= base;
      ans += v[i];
    }
    if (INT_MAX < ans) {
      return -1;
    }
    return (int)ans;
  }
};
