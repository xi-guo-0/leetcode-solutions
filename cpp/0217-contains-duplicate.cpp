class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    set<int> s;
    for (auto n : nums)
      if (s.find(n) != s.end())
        return true;
      else
        s.insert(n);
    return false;
  }
};
