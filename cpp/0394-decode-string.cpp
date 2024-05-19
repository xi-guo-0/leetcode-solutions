class Solution {
public:
  string decodeString(const string &s) {
    int num = 0;
    string ans;
    for (int i = 0; i < s.size(); ++i) {
      if (isalpha(s[i])) {
        ans.push_back(s[i]);
      } else if (isdigit(s[i])) {
        num = num * 10 + s[i] - '0';
      } else if (s[i] == '[') {
        int depth = 0;
        ++i;
        string inner;
        while (s[i] != ']' || depth) {
          if (s[i] == '[')
            ++depth;
          else if (s[i] == ']')
            --depth;
          inner.push_back(s[i]);
          ++i;
        }
        string inner_ans = decodeString(inner);
        while (0 < num) {
          ans += inner_ans;
          --num;
        }
      }
    }
    return ans;
  }
};
