#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    ostringstream os;
    const string lowerletters = "[a-z]*";
    vector<bool> result;
    os << lowerletters;
    for (const char ch : pattern)
      os << ch << lowerletters;
    regex r(os.str());
    for (const auto &s : queries)
      result.push_back(regex_match(s, r));
    return result;
  }
};

int main() { return 0; }
