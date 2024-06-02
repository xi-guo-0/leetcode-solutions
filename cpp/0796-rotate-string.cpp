#include <string>

using namespace std;

class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    string doubleS = s + s;
    return doubleS.find(goal) != string::npos;
  }
};

int main() { return 0; }
