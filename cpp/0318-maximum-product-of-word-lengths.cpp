class Solution {
public:
  int maxProduct(vector<string> &words) {
    int ans = 0;
    vector<unsigned> m(words.size(), 0);
    for (int i = 0; i < words.size(); ++i)
      m[i] = str2int(words[i]);
    for (int i = 0; i < words.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if ((m[i] & m[j]) == 0 && ans < words[i].size() * words[j].size())
          ans = words[i].size() * words[j].size();
      }
    }
    return ans;
  }

private:
  static int str2int(const string &s) {
    unsigned ans = 0;
    for (const auto &ch : s)
      ans |= 1 << (ch - 'a');
    return ans;
  }
};
