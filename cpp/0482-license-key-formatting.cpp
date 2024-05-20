class Solution {
public:
  string licenseKeyFormatting(const string &S, int K) {
    queue<char> q;
    ostringstream os;
    for (const char ch : S)
      if (ch != '-')
        q.push(toupper(ch));
    if (q.size() == 0) {
      return "";
    }
    int n = q.size() % K;
    if (n == 0)
      n = K;
    while (n--) {
      os << q.front();
      q.pop();
    }
    while (!q.empty()) {
      os << "-";
      for (int i = 0; i < K; i++) {
        os << q.front();
        q.pop();
      }
    }
    return os.str();
  }
};
