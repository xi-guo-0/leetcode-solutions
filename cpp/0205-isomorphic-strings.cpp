class Solution {
public:
  bool isIsomorphic(const string &s, const string &t) {
    char ms[256] = {0};
    char mt[256] = {0};
    char index = '!';
    ostringstream os;
    ostringstream ot;

    for (unsigned char ch : s) {
      if (!ms[ch])
        ms[ch] = index++;
      os << ms[ch];
    }

    index = '!';
    for (unsigned char ch : t) {
      if (!mt[ch])
        mt[ch] = index++;
      ot << mt[ch];
    }
    return os.str() == ot.str();
  }
};
