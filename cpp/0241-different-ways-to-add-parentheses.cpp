#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  std::vector<int> diffWaysToCompute(const std::string &input) {
    splitString(input);
    int len = number.size();
    memo = vector<vector<vector<int>>>(len,
                                       vector<vector<int>>(len, vector<int>()));
    return solve(0, len - 1);
  }

private:
  void splitString(const std::string &s) {
    number.clear();
    operators.clear();
    int x = 0;
    for (int i = 0; i < s.length(); ++i) {
      char c = s[i];
      if (!std::isdigit(c)) {
        number.push_back(x);
        operators.push_back(c);
        x = 0;
      } else {
        x = (x * 10) + c - '0';
      }
    }
    number.push_back(x);
  }

  static int calc(int a, int b, char op) {
    switch (op) {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    }
    return a + b;
  }

  std::vector<int> solve(int start, int end) {
    if (!memo[start][end].empty()) {
      return memo[start][end];
    }
    if (start == end) {
      memo[start][end] = {number[start]};
      return memo[start][end];
    }
    std::vector<int> ans;
    for (int i = start; i < end; ++i) {
      std::vector<int> left = solve(start, i);
      std::vector<int> right = solve(i + 1, end);
      for (int a : left) {
        for (int b : right) {
          ans.push_back(calc(a, b, operators[i]));
        }
      }
    }
    memo[start][end] = ans;
    return ans;
  }

  std::vector<int> number;
  std::vector<char> operators;
  std::vector<std::vector<std::vector<int>>> memo;
};

int main() { return 0; }
