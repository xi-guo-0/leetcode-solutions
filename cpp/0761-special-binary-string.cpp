#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string makeLargestSpecial(string S) {
    int balance = 0;
    int l = 0;
    vector<string> sub_ans;
    for (int r = 0; r < S.size(); ++r) {
      if (S[r] == '0') {
        --balance;
      } else {
        ++balance;
      }
      if (balance == 0) {
        sub_ans.push_back("1" + makeLargestSpecial(S.substr(l + 1, r - l - 1)) +
                          "0");
        l = r + 1;
      }
    }
    sort(sub_ans.rbegin(), sub_ans.rend());
    ostringstream os;
    for (const auto &word : sub_ans) {
      os << word;
    }
    return os.str();
  }
};

int main() { return 0; }
