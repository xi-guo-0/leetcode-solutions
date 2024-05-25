class Solution {
public:
  string toLowerCase(string str) {
    string ret;
    for (auto &c : str) {
      ret += tolower(c);
    }
    return ret;
  }
};
