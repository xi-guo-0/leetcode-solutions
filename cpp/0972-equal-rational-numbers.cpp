#include <cmath>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

class Solution {
public:
  bool isRationalEqual(string s, string t) {
    auto [value1, rep1] = convert(s);
    auto [value2, rep2] = convert(t);

    return fabs(value1 - value2) < 1e-9;
  }

private:
  pair<long double, long double> convert(const string &num) {
    regex re(R"((\d*)\.?(\d*)\(?(\d*)\)?)");
    smatch match;
    regex_search(num, match, re);

    string integerPart = match[1];
    string nonRepeatingPart = match[2];
    string repeatingPart = match[3];

    long double intPart = stold(integerPart.empty() ? "0" : integerPart);
    long double nonRepPart =
        nonRepeatingPart.empty() ? 0.0 : stold("0." + nonRepeatingPart);
    long double repPart = 0.0;

    if (!repeatingPart.empty()) {
      long double divisor = pow(10, repeatingPart.size()) - 1;
      repPart =
          stold(repeatingPart) / divisor / pow(10, nonRepeatingPart.size());
    }

    long double totalValue = intPart + nonRepPart + repPart;
    return {totalValue, repPart};
  };
};

int main() { return 0; }
