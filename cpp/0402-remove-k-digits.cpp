#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    int n = 0;
    vector<char> r;

    for (char c : num) {
      while (n > 0 && k > 0 && c < r[n - 1]) {
        r.pop_back();
        n--;
        k--;
      }

      r.push_back(c);
      n++;
    }

    while (k > 0 && n > 0) {
      r.pop_back();
      k--;
      n--;
    }

    int i = 0;

    while (i < n && r[i] == '0') {
      i++;
    }

    if (i == n) {
      return "0";
    } else {
      return string(r.begin() + i, r.end());
    }
  }
};
