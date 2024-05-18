#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> result;
    backtrack(result, num, target, "", 0, 0, 0, '+');
    return result;
  }

private:
  void backtrack(vector<string> &result, string &num, int target, string path,
                 long long int prevOperand, long long int currentOperand,
                 int index, char prevOp) {
    if (index == num.size()) {
      if (currentOperand == target) {
        result.push_back(path);
      }
      return;
    }

    for (int i = index; i < num.size(); ++i) {
      if (i != index && num[index] == '0')
        break;

      string currentStr = num.substr(index, i - index + 1);
      long long int currentValue = stoll(currentStr);

      if (index == 0) {
        backtrack(result, num, target, currentStr, currentValue, currentValue,
                  i + 1, '+');
      } else {
        backtrack(result, num, target, path + "+" + currentStr, currentValue,
                  currentOperand + currentValue, i + 1, '+');
        backtrack(result, num, target, path + "-" + currentStr, -currentValue,
                  currentOperand - currentValue, i + 1, '-');
        backtrack(result, num, target, path + "*" + currentStr,
                  prevOperand * currentValue,
                  currentOperand - prevOperand + (prevOperand * currentValue),
                  i + 1, '*');
      }
    }
  }
};

int main() {
  assert(
      (Solution().addOperators("123", 6) == vector<string>{"1*2*3", "1+2+3"}));
  return 0;
}
