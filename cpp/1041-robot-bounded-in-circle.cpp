#include <complex>
#include <string>

using namespace std;

class Solution {
public:
  bool isRobotBounded(string instructions) {
    complex<int> pos{0, 0};
    complex<int> step{0, 1};
    const complex<int> left{0, 1};
    const complex<int> right{0, -1};
    for (const char ch : instructions)
      if ('G' == ch)
        pos += step;
      else if ('L' == ch)
        step *= left;
      else if ('R' == ch)
        step *= right;
    return (pos == complex<int>{0, 0}) || (step != complex<int>{0, 1});
  }
};

int main() { return 0; }