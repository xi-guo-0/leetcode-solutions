#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &digits, int n) {

    string str_n = to_string(n);
    int len = str_n.size();
    int num_digits = digits.size();

    vector<int> dp(len + 1, 0);
    dp[len] = 1;

    for (int i = len - 1; i >= 0; --i) {

      char current_digit = str_n[i];

      for (const string &digit : digits) {
        if (digit[0] < current_digit) {
          dp[i] += pow(num_digits, len - i - 1);
        } else if (digit[0] == current_digit) {
          dp[i] += dp[i + 1];
        }
      }
    }

    int count_less_than_n = dp[0];

    for (int i = 1; i < len; ++i) {
      count_less_than_n += pow(num_digits, i);
    }

    return count_less_than_n;
  }
};

int main() { return 0; }
