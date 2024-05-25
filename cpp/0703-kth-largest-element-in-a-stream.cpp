class KthLargest {
public:
  KthLargest(int k, const vector<int> &nums) {
    this->k = k;
    this->nums = nums;
    sort(this->nums.rbegin(), this->nums.rend());
    while (this->nums.size() > k)
      this->nums.pop_back();
  }

  int add(int val) {
    if (nums.size() < k) {
      nums.push_back(val);
      stable_partition(nums.begin(), nums.end(),
                       [&val](int n) { return n >= val; });
    } else if (nums.back() < val) {
      nums.back() = val;
      stable_partition(nums.begin(), nums.end(),
                       [&val](int n) { return n >= val; });
    }
    return nums.back();
  }

private:
  int k;
  vector<int> nums;
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
