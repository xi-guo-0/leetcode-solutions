class Solution {
public:
  vector<int> findDuplicates(vector<int> &nums) {
    unordered_set<int> us;
    vector<int> v;
    for (auto n : nums) {
      if (us.find(n) != us.end())
        v.push_back(n);
      else
        us.insert(n);
    }
    return v;
  }
};
