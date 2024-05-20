class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(s.rbegin(), s.rend());
    sort(g.rbegin(), g.rend());
    int ans = 0;
    auto is = s.begin();
    auto ig = g.begin();
    while (is != s.end() && ig != g.end()) {
      if (*ig <= *is) {
        ++ans;
        ++is;
      }
      ++ig;
    }
    return ans;
  }
};
