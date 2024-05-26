#include <map>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
  string countOfAtoms(string const &formula) {
    auto m = parse(begin(formula), end(formula));
    ostringstream oss;
    for (auto const &p : m) {
      oss << p.first;
      if (1 < p.second) {
        oss << to_string(p.second);
      }
    }
    return oss.str();
  }

private:
  template <typename RandomIt>
  map<string, int> parse(RandomIt first, RandomIt last) {
    string atom;
    int count = 0;
    map<string, int> m;
    while (first < last) {
      char const ch = *first;
      if (isupper(ch)) {
        if (!atom.empty()) {
          m[atom] += max(count, 1);
          atom.clear();
          count = 0;
        }
        atom.push_back(ch);
      } else if (islower(ch)) {
        atom.push_back(ch);
      } else if (isdigit(ch)) {
        count *= 10;
        count += (ch - '0');
      } else if (ch == '(') {
        if (!atom.empty()) {
          m[atom] += max(count, 1);
          atom.clear();
          count = 0;
        }
        ++first;
        RandomIt p = first;
        int bucket = 1;
        while (first < last && bucket != 0) {
          if (*first == '(')
            ++bucket;
          if (*first == ')')
            --bucket;
          if (bucket == 0)
            break;
          ++first;
        }
        auto m1 = parse(p, first);
        count = 0;
        while (first + 1 < last && isdigit(*(first + 1))) {
          ++first;
          count *= 10;
          count += (*first - '0');
        }
        count = max(count, 1);
        for (auto const &p : m1) {
          m[p.first] += p.second * count;
        }
        count = 0;
      }
      ++first;
    }
    if (!atom.empty())
      m[atom] += max(count, 1);
    return m;
  }
};

int main() { return 0; }
