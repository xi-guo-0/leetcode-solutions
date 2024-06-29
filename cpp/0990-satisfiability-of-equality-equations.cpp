#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool equationsPossible(vector<string> &equations) {
    unordered_map<char, char> f;
    for (char c = 'a'; c <= 'z'; ++c) {
      f[c] = c;
    }

    vector<pair<char, char>> ne;

    for (const auto &e : equations) {
      char a = e[0];
      char b = e[3];
      if (b < a) {
        char c = a;
        a = b;
        b = c;
      }

      if (e[1] == '=') {
        f[findParent(a, f)] = findParent(b, f);
      } else {
        ne.emplace_back(a, b);
      }
    }

    for (const auto &pair : ne) {
      if (findParent(pair.first, f) == findParent(pair.second, f)) {
        return false;
      }
    }

    return true;
  }

private:
  char findParent(char x, unordered_map<char, char> &f) {
    while (x != f[x]) {
      f[x] = f[f[x]];
      x = f[x];
    }
    return x;
  }
};

int main() { return 0; }
