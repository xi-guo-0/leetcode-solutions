#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findAndReplacePattern(const vector<string> &words,
                                       const string &pattern) {
    vector<string> result;
    for (const auto &word : words) {
      if (matchPattern(word, pattern) && matchPattern(pattern, word)) {
        result.push_back(word);
      }
    }
    return result;
  }

private:
  bool matchPattern(const string &word, const string &pattern) {
    unordered_map<char, char> word_to_pattern;
    for (int i = 0; i < word.size(); ++i) {
      char w = word[i];
      char p = pattern[i];
      if (word_to_pattern.find(w) == word_to_pattern.end()) {
        word_to_pattern[w] = p;
      } else {
        if (word_to_pattern[w] != p) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() { return 0; }
