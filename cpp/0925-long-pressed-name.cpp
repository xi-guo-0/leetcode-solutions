#include <string>

using namespace std;

class Solution {
public:
  bool isLongPressedName(const string &name, const string &typed) {
    if (name.empty() || typed.empty()) {
      return false;
    }
    int i = 0;
    int j = 0;
    while (i < name.size()) {
      if (name[i] != typed[j])
        return false;
      int k = i + 1;
      while (k < name.size() && name[i] == name[k])
        k++;
      const int cn = k - i;
      i = k;
      k = j + 1;
      while (k < typed.size() && typed[j] == typed[k])
        k++;
      const int ct = k - j;
      j = k;
      if (ct < cn)
        return false;
    }
    if (j < typed.size())
      return false;
    return true;
  }
};

int main() { return 0; }
