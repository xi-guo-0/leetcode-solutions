class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(begin(houses), end(houses));
    sort(begin(heaters), end(heaters));
    int ans = 0;
    int constexpr m = numeric_limits<int>::max();
    for (int const house : houses) {
      int l = m;
      int r = m;
      auto p = lower_bound(begin(heaters), end(heaters), house);
      if (p != end(heaters)) {
        r = (*p) - house;
      }
      if (p != begin(heaters)) {
        l = house - (*prev(p));
      }
      ans = max(ans, min(l, r));
    }
    return ans;
  }
};
