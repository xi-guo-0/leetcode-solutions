#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class WordFilter {
public:
  unordered_map<string, int> prefixSuffixMap;

  WordFilter(vector<string> &words) {
    for (int index = 0; index < words.size(); ++index) {
      const string &word = words[index];
      int wordLength = word.size();
      for (int i = 0; i <= wordLength; ++i) {
        string prefix = word.substr(0, i);
        for (int j = 0; j <= wordLength; ++j) {
          string suffix = word.substr(wordLength - j);
          prefixSuffixMap[prefix + "#" + suffix] = index;
        }
      }
    }
  }

  int f(string prefix, string suffix) {
    string key = prefix + "#" + suffix;
    if (prefixSuffixMap.find(key) != prefixSuffixMap.end()) {
      return prefixSuffixMap[key];
    }
    return -1;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */

int main() { return 0; }
