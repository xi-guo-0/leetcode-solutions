#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    auto isValid = [](const std::string &str) -> bool {
      int balance = 0;
      for (char c : str) {
        if (c == '(') {
          balance++;
        } else if (c == ')') {
          balance--;
        }
        if (balance < 0) {
          return false;
        }
      }
      return balance == 0;
    };

    std::unordered_set<std::string> level = {s};
    while (true) {
      std::vector<std::string> cur;
      for (const auto &item : level) {
        if (isValid(item)) {
          cur.push_back(item);
        }
      }
      if (!cur.empty()) {
        return cur;
      }
      std::unordered_set<std::string> nextLevel;
      for (const auto &item : level) {
        for (size_t i = 0; i < item.size(); ++i) {
          if (item[i] == '(' || item[i] == ')') {
            nextLevel.insert(item.substr(0, i) + item.substr(i + 1));
          }
        }
      }
      level = std::move(nextLevel);
    }
  }
};
