#include <algorithm>
#include <array>
#include <cassert>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
concept Printable = requires(std::ostream &os, T t) {
                      { os << t } -> std::convertible_to<std::ostream &>;
                    };

template <typename T>
  requires Printable<T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  os << "[";
  bool first = true;
  for (const auto &elem : vec) {
    if (!first)
      os << ", ";
    os << elem;
    first = false;
  }
  os << "]";
  return os;
}

template <typename T>
concept Subtractable = requires(T a, T b) {
                         { a - b } -> std::same_as<T>;
                       };

template <typename T>
  requires Subtractable<T>
std::vector<T> operator-(const std::vector<T> &vec1,
                         const std::vector<T> &vec2) {
  if (vec1.size() != vec2.size()) {
    throw std::invalid_argument(
        "Vectors must have the same size for subtraction");
  }
  std::vector<T> result;
  result.reserve(vec1.size());
  for (std::size_t i = 0; i < vec1.size(); ++i) {
    result.push_back(vec1[i] - vec2[i]);
  }
  return result;
}

// clang-format off
/**
 *  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
 * [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1] zero
 * [0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] one
 * [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0] two
 * [0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0] three
 * [0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0] four
 * [0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0] five
 * [0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0] six
 * [0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0] seven
 * [0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0] eight
 * [0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0] nine
 * z -> zero
 * x -> six
 * w -> two
 * u -> four
 * g -> eight
 *
 * t -> three
 * s -> seven
 * v -> five
 * i -> nine
 * one
 */
// clang-format on

class Solution {
private:
public:
  string originalDigits(string s) {
    auto chars_counts = CountChars(s);
    vector<string> digits_strs{"zero", "one", "two",   "three", "four",
                               "five", "six", "seven", "eight", "nine"};
    vector<vector<size_t>> digits_counts;
    vector<size_t> counts(digits_strs.size(), 0);
    for (const auto &digit_str : digits_strs) {
      digits_counts.push_back(CountChars(digit_str));
    }
    for (auto [ch, n] : vector<pair<char, size_t>>{{'z', 0},
                                                   {'x', 6},
                                                   {'w', 2},
                                                   {'u', 4},
                                                   {'g', 8},
                                                   {'t', 3},
                                                   {'s', 7},
                                                   {'v', 5},
                                                   {'i', 9},
                                                   {'o', 1}}) {
      while (chars_counts[ch - 'a'] > 0) {
        chars_counts = chars_counts - digits_counts[n];
        counts[n] += 1;
      }
    }
    ostringstream oss;
    for (size_t i = 0; i < 10; ++i) {
      for (size_t j = 0; j < counts[i]; ++j) {
        oss << i;
      }
    }
    return oss.str();
  }

private:
  vector<size_t> CountChars(const string &s) {
    vector<size_t> a(26, 0);
    for (const char ch : s) {
      a[ch - 'a'] += 1;
    }
    return a;
  }
};

int main() {
  Solution solution;
  solution.originalDigits("owoztneoer");
  return 0;
}
