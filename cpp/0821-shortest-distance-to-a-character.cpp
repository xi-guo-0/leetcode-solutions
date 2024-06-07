#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> shortestToChar(const string &S, const char C) {
    vector<int> v(S.size(), S.size());
    int pos = -S.size();
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == C)
        pos = i;
      v[i] = min(v[i], i - pos);
    }
    pos = S.size() + S.size();
    for (int i = S.size() - 1; 0 <= i; i--) {
      if (S[i] == C)
        pos = i;
      v[i] = min(v[i], pos - i);
    }
    return v;
  }
};

int main() { return 0; }
