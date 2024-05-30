#include <cmath>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int numSteps(string s) {

    int steps = 0;
    int carry = 0;
    int n = s.size();

    for (int i = n - 1; i > 0; --i) {
      if (s[i] - '0' + carry == 1) {
        carry = 1;
        steps += 2;
      } else {
        steps += 1;
      }
    }

    return steps + carry;
  }
};

int main() {
  cout << "Example 1: " << numSteps("1101") << endl;
  cout << "Example 2: " << numSteps("10") << endl;
  cout << "Example 3: " << numSteps("1") << endl;
  return 0;
}
