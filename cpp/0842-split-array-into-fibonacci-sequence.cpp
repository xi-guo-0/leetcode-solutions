#include <limits>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> splitIntoFibonacci(string num) {
    vector<int> result;
    int n = num.size();

    for (int i = 1; i <= n / 2; ++i) {
      if (num[0] == '0' && i > 1)
        break;
      long long first = stoll(num.substr(0, i));
      if (first > numeric_limits<int>::max())
        break;

      for (int j = 1; j <= (n - i) / 2; ++j) {
        if (num[i] == '0' && j > 1)
          break;
        long long second = stoll(num.substr(i, j));
        if (second > numeric_limits<int>::max())
          break;

        result = {static_cast<int>(first), static_cast<int>(second)};
        if (isValidFibonacciSequence(num, i + j, first, second, result)) {
          return result;
        }
        result.clear();
      }
    }

    return {};
  }

private:
  bool isValidFibonacciSequence(const string &num, int start, long long first,
                                long long second, vector<int> &result) {
    int n = num.size();
    while (start < n) {
      long long next = first + second;
      if (next > numeric_limits<int>::max())
        return false;
      string nextStr = to_string(next);
      if (num.substr(start, nextStr.size()) != nextStr)
        return false;
      start += nextStr.size();
      result.push_back(static_cast<int>(next));
      first = second;
      second = next;
    }
    return true;
  }
};

int main() { return 0; }
