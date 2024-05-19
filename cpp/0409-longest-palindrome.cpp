#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> map;

    for (char c : s) {
      if (map.find(c) == map.end()) {
        map[c] = 1;
      } else {
        map[c]++;
      }
    }

    int count = 0;

    for (auto &pair : map) {
      count += pair.second >> 1 << 1;
    }

    if (count < s.length()) {
      count++;
    }

    return count;
  }
};
