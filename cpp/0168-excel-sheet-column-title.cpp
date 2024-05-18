class Solution {
public:
  string convertToTitle(int n) {
    if (n == 0) {
      return "";
    } else if (n == 1) {
      return "A";
    }
    stack<char> s;
    ostringstream os;
    while (n != 0) {
      n--;
      s.push(n % 26 + 'A');
      n /= 26;
    }
    while (!s.empty()) {
      os << s.top();
      s.pop();
    }
    return os.str();
  }
};
