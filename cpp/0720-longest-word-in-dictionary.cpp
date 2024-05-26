#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestWord(vector<string> &words) {
    sort(words.begin(), words.end());
    set<string> dict;
    dict.insert("");
    size_t n = 0;
    for (const auto &word : words) {
      bool isMatch = true;
      for (int i = 0; i < word.size(); i++)
        if (!dict.count(word.substr(0, i))) {
          isMatch = false;
          break;
        }
      if (isMatch) {
        n = max(n, word.size());
        dict.insert(word);
      }
    }
    for (const auto &s : dict) {
      if (s.size() == n)
        return s;
    }
    return "";
  }
};

int main() { return 0; }
