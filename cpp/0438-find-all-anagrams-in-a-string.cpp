static inline constexpr int c2n(char const ch) { return ch - 'a'; }
class Solution {
public:
  vector<int> findAnagrams(string const &s, string const &p) {
    if (s.size() < p.size()) {
      return {};
    }
    vector<int> balance(26, 0);
    vector<int> ans;
    for (int i = 0; i < p.size(); ++i) {
      ++balance[c2n(s[i])];
      --balance[c2n(p[i])];
    }
    if (all_of(begin(balance), end(balance),
               [](int const i) { return i == 0; })) {
      ans.push_back(0);
    }
    for (int i = p.size(); i < s.size(); ++i) {
      ++balance[c2n(s[i])];
      --balance[c2n(s[i - p.size()])];
      if (all_of(begin(balance), end(balance),
                 [](int const i) { return i == 0; })) {
        ans.push_back(i - p.size() + 1);
      }
    }
    return ans;
  }
};
