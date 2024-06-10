#include <cstddef>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<string> &vs) {
  os << "{";
  for (const auto &s : vs) {
    os << "\"" << s << "\""
       << ",";
  }
  os << "}";
  return os;
}

vector<string> group(const string &s) {
  vector<string> ans;
  if (!s.empty()) {
    ans.push_back(s.substr(0, 1));
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i - 1] == s[i]) {
        ans.back().push_back(s[i]);
      } else {
        ans.push_back(s.substr(i, 1));
      }
    }
  }
  return ans;
}

class Solution {
public:
  string pushDominoes(string dominoes) {
    auto gs = group(dominoes);
    for (size_t i = 0; i < gs.size(); ++i) {
      if (gs[i].front() == '.') {
        bool push_right = 0 < i && gs[i - 1].front() == 'R';
        bool push_left = i < gs.size() - 1 && gs[i + 1].front() == 'L';
        if (push_left && push_right) {
          auto &a = gs[i];
          auto mid = a.size() / 2;
          for (size_t j = 0; j < mid; ++j) {
            a[j] = 'R';
          }
          for (size_t j = mid; j < a.size(); ++j) {
            a[j] = 'L';
          }
          if (a.size() % 2 == 0) {
          } else {
            a[mid] = '.';
          }
        } else if (push_left) {
          for (auto &c : gs[i]) {
            c = 'L';
          }
        } else if (push_right) {
          for (auto &c : gs[i]) {
            c = 'R';
          }
        } else {
        }
      }
    }
    ostringstream oss;
    for (const auto &s : gs) {
      oss << s;
    }
    return oss.str();
  }
};

int main() {
  Solution solution;
  solution.pushDominoes(".L.R...LR..L..");
  return 0;
}
