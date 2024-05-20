#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findWords(vector<string> &words) {
    vector<string> result;
    unordered_map<char, int> map = {
        {'Q', 1}, {'q', 1}, {'W', 1}, {'w', 1}, {'E', 1}, {'e', 1}, {'R', 1},
        {'r', 1}, {'T', 1}, {'t', 1}, {'Y', 1}, {'y', 1}, {'U', 1}, {'u', 1},
        {'I', 1}, {'i', 1}, {'O', 1}, {'o', 1}, {'P', 1}, {'p', 1}, {'A', 2},
        {'a', 2}, {'S', 2}, {'s', 2}, {'D', 2}, {'d', 2}, {'F', 2}, {'f', 2},
        {'G', 2}, {'g', 2}, {'H', 2}, {'h', 2}, {'J', 2}, {'j', 2}, {'K', 2},
        {'k', 2}, {'L', 2}, {'l', 2}, {'Z', 3}, {'z', 3}, {'X', 3}, {'x', 3},
        {'C', 3}, {'c', 3}, {'V', 3}, {'v', 3}, {'B', 3}, {'b', 3}, {'N', 3},
        {'n', 3}, {'M', 3}, {'m', 3}};

    for (const string &word : words) {
      bool isOneRow = true;
      int type = map[word[0]];
      for (int i = 1; i < word.length(); i++) {
        if (type != map[word[i]]) {
          isOneRow = false;
          break;
        }
      }
      if (isOneRow) {
        result.push_back(word);
      }
    }

    return result;
  }
};
