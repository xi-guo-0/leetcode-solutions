#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  char findTheDifference(string s, string t) {
    unordered_map<char, int> map = {
        {'a', 0}, {'f', 0}, {'k', 0}, {'o', 0}, {'s', 0}, {'w', 0}, {'b', 0},
        {'g', 0}, {'l', 0}, {'p', 0}, {'t', 0}, {'x', 0}, {'c', 0}, {'h', 0},
        {'m', 0}, {'q', 0}, {'u', 0}, {'y', 0}, {'d', 0}, {'i', 0}, {'n', 0},
        {'r', 0}, {'v', 0}, {'z', 0}, {'e', 0}, {'j', 0}};

    for (char c : t) {
      map[c]++;
    }

    char result = 'a';
    for (char c : s) {
      map[c]--;
    }

    for (auto &entry : map) {
      if (entry.second == 1) {
        result = entry.first;
        break;
      }
    }

    return result;
  }
};
