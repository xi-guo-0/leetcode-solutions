class Solution {
public:
  int shoppingOffers(const vector<int> &price,
                     const vector<vector<int>> &special,
                     const vector<int> &needs) {
    map<vector<int>, int> dict;
    function<int(const vector<int> &)> shopping;
    shopping = [&price, &special, &dict, &shopping](const vector<int> &status) {
      if (dict.count(status))
        return dict[status];
      int ans = inner_product(status.begin(), status.end(), price.begin(), 0);
      int j = 0;
      for (const auto &s : special) {
        vector<int> next_status(status);
        for (j = 0; j < status.size(); j++) {
          next_status[j] -= s[j];
          if (next_status[j] < 0)
            break;
        }
        if (j == status.size())
          ans = min(ans, s.back() + shopping(next_status));
      }
      dict[status] = ans;
      return ans;
    };

    return shopping(needs);
  }
};
