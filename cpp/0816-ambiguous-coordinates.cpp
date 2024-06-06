#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generate_valid_decimals(const string &s) {
  vector<string> results;

  if (s == "0" || s[0] != '0') {
    results.push_back(s);
  }

  if (s.size() > 1 && s[0] == '0' &&
      any_of(s.begin(), s.end(), [](char ch) { return ch != '0'; })) {
    results.push_back("0." + s.substr(1));
  } else {
    for (size_t i = 1; i < s.size(); ++i) {
      string left = s.substr(0, i);
      string right = s.substr(i);

      if (right.back() != '0') {
        results.push_back(left + "." + right);
      }
    }
  }

  results.erase(remove_if(results.begin(), results.end(),
                          [](const string &str) {
                            return str.back() == '0' &&
                                   str.find('.') != string::npos;
                          }),
                results.end());

  return results;
}

class Solution {
public:
  vector<string> ambiguousCoordinates(string s) {
    vector<string> result;

    string num = s.substr(1, s.size() - 2);

    for (size_t i = 1; i < num.size(); ++i) {
      string left = num.substr(0, i);
      string right = num.substr(i);

      vector<string> left_coords = generate_valid_decimals(left);
      vector<string> right_coords = generate_valid_decimals(right);

      for (const string &l : left_coords) {
        for (const string &r : right_coords) {
          result.push_back("(" + l + ", " + r + ")");
        }
      }
    }

    return result;
  }
};

int main() { return 0; }
