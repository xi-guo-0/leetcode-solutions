#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;

class Solution {
public:
  Solution(vector<int> &w) {
    prefixSum.resize(w.size());
    prefixSum[0] = w[0];
    for (int i = 1; i < w.size(); ++i) {
      prefixSum[i] = prefixSum[i - 1] + w[i];
    }
  }

  int pickIndex() {
    uniform_int_distribution<int> dist(0, prefixSum.back() - 1);
    int target = dist(gen);
    auto it = upper_bound(prefixSum.begin(), prefixSum.end(), target);
    return it - prefixSum.begin();
  }

private:
  vector<int> prefixSum;
  mt19937 gen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
