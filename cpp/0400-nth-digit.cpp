class Solution {
public:
  static int constexpr N = 1e8;
  vector<long> v;
  Solution() {
    v.push_back(0l);
    for (int i = 1, n = 10; n <= N; ++i, n *= 10) {
      v.push_back(v.back() + static_cast<long>(i) * (n - n / 10));
    }
  }
  int findNthDigit(int n) {
    int k = lower_bound(v.begin(), v.end(), n) - v.begin();
    int u = pow(10, k - 1) + (n - v[k - 1] - 1) / k;
    int x = (n - v[k - 1] - 1) % k;
    return (u / (int)pow(10, k - 1 - x)) % 10;
  }
};
