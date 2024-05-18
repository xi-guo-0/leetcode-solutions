class Solution {
public:
  bool containsNearbyAlmostDuplicate(const vector<int> &nums, const int k,
                                     const int t) {
    if (t < 0)
      return false;
    unordered_map<long long, long long> dict;
    long long w = static_cast<long long>(t) + 1;
    for (long long i = 0; i < nums.size(); ++i) {
      long long id = get_id(nums[i], w);
      if (dict.count(id))
        return true;
      if (dict.count(id - 1) && abs(nums[i] - dict[id - 1]) < w)
        return true;
      if (dict.count(id + 1) && abs(nums[i] - dict[id + 1]) < w)
        return true;
      dict[id] = nums[i];
      if (k <= i)
        dict.erase(get_id(nums[i - k], w));
    }
    return false;
  }

private:
  long long get_id(const long long x, const long long w) {
    return x < 0 ? (x + 1) / w - 1 : x / w;
  }
};
