#include <cstdlib>
#include <ctime>
#include <unordered_set>
#include <vector>

class Solution {
public:
  Solution(int n_rows, int n_cols) {
    m = n_rows;
    n = n_cols;
    mByn = m * n;
    srand(47);
  }

  vector<int> flip() {
    vector<int> ans(2);
    int t = rand() % mByn;
    while (set.find(t) != set.end()) {
      t = rand() % mByn;
    }
    set.insert(t);
    ans[0] = t / n;
    ans[1] = t % n;
    return ans;
  }

  void reset() { set.clear(); }

private:
  unordered_set<int> set;
  int m;
  int n;
  int mByn;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
