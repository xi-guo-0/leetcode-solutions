class Solution {
public:
  string complexNumberMultiply(string a, string b) {
    auto parse = [](const string &s) {
      int x = 0, y = 0;
      int sign_pos = s.find('+');
      x = stoi(s.substr(0, sign_pos));
      y = stoi(s.substr(sign_pos + 1, s.size() - sign_pos - 2));
      return make_pair(x, y);
    };

    auto [x1, y1] = parse(a);
    auto [x2, y2] = parse(b);

    ostringstream os;
    os << (x1 * x2 - y1 * y2) << "+" << (x1 * y2 + x2 * y1) << "i";
    return os.str();
  }
};
