#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string toGoatLatin(const string &S) {
    if (S.empty()) {
      return S;
    }

    istringstream is(S);
    ostringstream os;
    string word;
    unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U',
                               'a', 'e', 'i', 'o', 'u'};
    int wordCount = 0;

    while (is >> word) {
      if (wordCount > 0) {
        os << " ";
      }

      if (vowels.count(word[0])) {
        os << word << "ma";
      } else {
        os << word.substr(1) << word[0] << "ma";
      }

      os << string(++wordCount, 'a');
    }

    return os.str();
  }
};

int main() { return 0; }
