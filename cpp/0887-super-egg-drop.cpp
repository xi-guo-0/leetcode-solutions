class Solution {
public:
  int superEggDrop(int k, int n) {
    int lo = 1, hi = n;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (f(mi, k, n) < n)
        lo = mi + 1;
      else
        hi = mi;
    }
    return lo;
  }

private:
  int f(int x, int k, int n) {
    int ans = 0, r = 1;
    for (int i = 1; i <= k; ++i) {
      r *= x - i + 1;
      r /= i;
      ans += r;
      if (ans >= n)
        break;
    }
    return ans;
  }
};

int main() { return 0; }
