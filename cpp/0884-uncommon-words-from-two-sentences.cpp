#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> uncommonFromSentences(const string &A, const string &B) {
    set<string> sa;
    set<string> sb;
    istringstream ia(A);
    istringstream ib(B);
    string s;
    while (ia >> s) {
      if (sa.count(s))
        sb.insert(s);
      sa.insert(s);
    }
    while (ib >> s) {
      if (sb.count(s))
        sa.insert(s);
      sb.insert(s);
    }
    vector<string> result;
    set_symmetric_difference(sa.begin(), sa.end(), sb.begin(), sb.end(),
                             back_inserter(result));
    return result;
  }
};

int main() { return 0; }
