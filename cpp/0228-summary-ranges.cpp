class Solution {
public:
  vector<string> summaryRanges(const vector<int> &nums) {
    vector<string> res;
    auto first = nums.begin();
    auto last = nums.end();
    while (first != last) {
      auto p = next(first);
      while (p != last && *prev(p) + 1 == *p)
        p++;
      if (next(first) == p) {
        res.push_back(to_string(*first));
      } else {
        res.push_back(to_string(*first) + "->" + to_string(*prev(p)));
      }
      first = p;
    }
    return res;
  }
};
