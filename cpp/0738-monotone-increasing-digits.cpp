#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    std::string num = std::to_string(n);
    int len = num.size();

    int mark = len;

    for (int i = len - 1; i > 0; --i) {
      if (num[i] < num[i - 1]) {
        mark = i;
        num[i - 1]--;
      }
    }

    for (int i = mark; i < len; ++i) {
      num[i] = '9';
    }

    return std::stoi(num);
  }
};

int main() {
  Solution solution;
  solution.monotoneIncreasingDigits(10);
  solution.monotoneIncreasingDigits(1234);
  solution.monotoneIncreasingDigits(332);
  return 0;
}
