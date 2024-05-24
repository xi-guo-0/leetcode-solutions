#include <cstddef>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
  string solveEquation(string equation) {
    auto [lhsCoef, lhsConst] =
        splitAndCalculate(equation.substr(0, equation.find('=')));
    auto [rhsCoef, rhsConst] =
        splitAndCalculate(equation.substr(equation.find('=') + 1));
    int coefficient = lhsCoef - rhsCoef;
    int constant = rhsConst - lhsConst;

    if (coefficient == 0)
      return constant == 0 ? "Infinite solutions" : "No solution";
    return "x=" + std::to_string(constant / coefficient);
  }

private:
  std::pair<int, int> splitAndCalculate(const std::string &s) {
    int coefficient = 0, constant = 0, num = 0, sign = 1;
    for (size_t i = 0; i < s.size(); ++i) {
      const char c = s[i];
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      } else if (c == '+' || c == '-') {
        constant += sign * num;
        sign = c == '+' ? 1 : -1;
        num = 0;
      } else {
        if (0 < i && num == 0 && s[i - 1] == '0') {
        } else {
          coefficient += num == 0 ? sign : sign * num;
          num = 0;
        }
      }
    }
    return {coefficient, constant + sign * num};
  }
};

int main() {
  Solution solution;
  cout << solution.solveEquation("x+5-3+x=6+x-2") << endl;
  return 0;
}
