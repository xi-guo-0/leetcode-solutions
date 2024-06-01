#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string customSortString(string S, string T) {
    sort(begin(T), end(T), [&S](char a, char b) {
      return S.find_first_of(a) < S.find_first_of(b);
    });
    return T;
  }
};

int main() { return 0; }
