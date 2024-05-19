class Solution {
private:
  vector<int> ori;
  vector<int> cur;
  const int sz;
  default_random_engine e;

public:
  Solution(vector<int> &nums) : sz(nums.size()) {
    ori = nums;
    cur = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return ori; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = 0; i < sz; ++i) {
      const int j = (e() % (sz - i)) + i;
      swap(cur[i], cur[j]);
    }
    return cur;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
