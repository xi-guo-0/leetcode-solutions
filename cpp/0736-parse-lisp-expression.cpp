#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

std::vector<std::string> Parse(const std::string &text) {
  const std::regex ws_re("([\\(\\)])|([^\\(\\)\\s]+)");
  const std::vector<int> submatches{0};
  std::vector<std::string> result;
  std::copy(
      std::sregex_token_iterator(text.begin(), text.end(), ws_re, submatches),
      std::sregex_token_iterator(), std::back_inserter(result));

  return result;
}

int Eval(const vector<string> exps, int &idx,
         const unordered_map<string, int> &env) {
  string s = exps[idx];
  idx += 1;
  if (s == "(") {
    s = exps[idx];
    idx += 1;
    int ans = 0;
    if (s == "add") {
      const auto v0 = Eval(exps, idx, env);
      const auto v1 = Eval(exps, idx, env);
      ans = v0 + v1;
    } else if (s == "mult") {
      const auto v0 = Eval(exps, idx, env);
      const auto v1 = Eval(exps, idx, env);
      ans = v0 * v1;
    } else {
      auto new_env = env;
      while (exps[idx] != "(" && exps[idx + 1] != ")") {
        const auto &var = exps[idx];
        idx += 1;
        const auto val = Eval(exps, idx, new_env);
        new_env[var] = val;
      }
      ans = Eval(exps, idx, new_env);
    }
    idx += 1;
    return ans;
  } else if ((::isdigit(s[0]) || s[0] == '-') &&
             std::all_of(next(s.begin()), s.end(), ::isdigit)) {
    return stoi(s);
  } else {
    return env.at(s);
  }
}

/*
vector<string> Parse(const string &text) {
  const std::regex ws_re("[\\( \\)]");
  const std::vector<int> submatches{-1, 0};
  std::vector<string> result;
  std::copy(
      std::sregex_token_iterator(text.begin(), text.end(), ws_re, submatches),
      std::sregex_token_iterator(), std::back_inserter(result));
  result.erase(std::remove_if(
                   result.begin(), result.end(),
                   [](const std::string &s) { return s.empty() || s == " "; }),
               result.end());
  return result;
}
*/

class Solution {
public:
  int evaluate(string expression) {
    auto exps = Parse(expression);
    const unordered_map<string, int> env;
    int idx = 0;
    return Eval(exps, idx, env);
  }
};

int main() {
  Solution solution;
  cout << solution.evaluate("(let x 7 -12)") << "\n";
  return 0;
}
