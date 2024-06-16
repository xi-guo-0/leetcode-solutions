#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int superpalindromesInRange(string left, string right) {
    uint64_t L = stoull(left);
    uint64_t R = stoull(right);

    int count = 0;

    for (int i = 1; i < 100000; ++i) {
      string s = to_string(i);
      string rev_s = s;
      reverse(rev_s.begin(), rev_s.end());
      uint64_t num = stoull(s + rev_s.substr(1));

      if (num > R)
        break;

      if (num >= sqrt(L) && num * num <= R &&
          isPalindrome(to_string(num * num))) {
        ++count;
      }
    }

    for (int i = 1; i < 100000; ++i) {
      string s = to_string(i);
      string rev_s = s;
      reverse(rev_s.begin(), rev_s.end());
      uint64_t num = stoull(s + rev_s);

      if (num > R)
        break;

      if (num >= sqrt(L) && num * num <= R &&
          isPalindrome(to_string(num * num))) {
        ++count;
      }
    }

    return count;
  }

private:
  bool isPalindrome(const string &s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s[i++] != s[j--])
        return false;
    }
    return true;
  }
};

int main() { return 0; }
