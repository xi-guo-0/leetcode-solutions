#include <cstddef>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    auto c2u = [](char ch) { return ch - 'a'; };
    size_t count[26]{};
    for (char ch : magazine) {
      count[c2u(ch)] += 1;
    }
    for (char ch : ransomNote) {
      if (count[c2u(ch)] == 0) {
        return false;
      }
      count[c2u(ch)] -= 1;
    }
    return true;
  }
};
