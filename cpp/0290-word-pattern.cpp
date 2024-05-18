class Solution {
public:
  bool wordPattern(const string &pattern, const string &str) {
    int index = 0;
    map<char, int> mp;
    map<string, int> ms;
    vector<int> pp;
    vector<int> ps;
    istringstream is(str);
    string s;
    for (char ch : pattern) {
      if (!mp.count(ch))
        mp[ch] = index++;
      pp.push_back(mp[ch]);
    }

    index = 0;
    while (is >> s) {
      if (!ms.count(s))
        ms[s] = index++;
      ps.push_back(ms[s]);
    }
    if (pp.size() != ps.size()) {
      return false;
    }
    for (int i = 0; i < pp.size(); i++)
      if (pp[i] != ps[i])
        return false;
    return true;
  }
};
