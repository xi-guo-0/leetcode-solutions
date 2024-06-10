#include <string>

using namespace std;

class Solution {
public:
  bool backspaceCompare(const string &S, const string &T) {
    string a;
    string b;
    for (const char ch : S)
      if (ch == '#') {
        if (!a.empty())
          a.pop_back();
      } else
        a.push_back(ch);
    for (const char ch : T)
      if (ch == '#') {
        if (!b.empty())
          b.pop_back();
      } else
        b.push_back(ch);
    return a == b;
  }
};

int main() { return 0; }
