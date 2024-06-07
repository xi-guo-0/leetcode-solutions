#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string mostCommonWord(string paragraph, const vector<string> &banned) {
    set<string> bs(banned.begin(), banned.end());
    map<string, int> msi;
    int count = 0;
    transform(paragraph.begin(), paragraph.end(), paragraph.begin(),
              [](unsigned char c) -> unsigned char {
                return isalpha(c) ? tolower(c) : ' ';
              });
    istringstream is(paragraph);
    string s;
    while (is >> s) {
      if (bs.find(s) == bs.end()) {
        if (msi.find(s) != msi.end()) {
          msi[s] += 1;
          count = max(count, msi[s]);
        } else
          msi[s] = 1;
      }
    }
    for (const auto &m : msi)
      if (m.second == count)
        return m.first;
    return msi.begin()->first;
  }
};

int main() { return 0; }
