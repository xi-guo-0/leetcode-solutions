#include <vector>

using namespace std;

class Solution {
public:
  char nextGreatestLetter(const vector<char> &letters, const char target) {
    const auto p = upper_bound(letters.begin(), letters.end(), target);
    if (p == letters.end())
      return letters.front();
    return *p;
  }
};

int main() { return 0; }
