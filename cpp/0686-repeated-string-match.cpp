class Solution {
public:
  int repeatedStringMatch(const string &a, const string &b) {
    string t(a);
    int count = 1;
    while (t.size() <= b.size() + a.size()) {
      if (t.find(b) != string::npos) {
        return count;
      } else {
        t += a;
        count++;
      }
    }

    return t.find(b) != string::npos ? count : -1;
  }
};
