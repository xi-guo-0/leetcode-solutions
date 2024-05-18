#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class BinaryIndexedTree {
public:
  BinaryIndexedTree(int n) { c.resize(n * 2); }

  static int lowbit(int x) { return x & (-x); }

  int ask(int x) {
    int ans = 0;
    for (; x > 0; x -= lowbit(x)) {
      ans += c[x];
    }
    return ans;
  }

  void add(int x, int y) {
    for (; x < c.size(); x += lowbit(x)) {
      c[x] += y;
    }
  }

private:
  std::vector<int> c;
};

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    std::vector<int> a(nums);
    std::sort(a.begin(), a.end());
    std::unordered_map<int, int> m;
    for (int i = 0; i < a.size(); ++i) {
      m[a[i]] = i + 1;
    }
    BinaryIndexedTree t(nums.size());
    std::vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
      ans[i] = t.ask(m[nums[i]] - 1);
      t.add(m[nums[i]], 1);
    }
    return ans;
  }
};
