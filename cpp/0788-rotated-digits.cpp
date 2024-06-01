#include <algorithm>
#include <string>

class Solution {
public:
  int rotatedDigits(int N) {
    int count = 0;
    for (int i = 2; i <= N; i++) {
      string s = to_string(i);
      if (any_of(s.begin(), s.end(),
                 [](char c) { return c == '3' || c == '4' || c == '7'; })) {
        continue;
      }
      if (any_of(s.begin(), s.end(), [](char c) {
            return c == '2' || c == '5' || c == '6' || c == '9';
          })) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  return 0;
}
