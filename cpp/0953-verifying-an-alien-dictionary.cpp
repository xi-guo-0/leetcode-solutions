#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAlienSorted(vector<string> &words, string &order) {
    auto compchar = [&order](const char a, const char b) {
      return order.find(a) < order.find(b);
    };
    auto compstring = [&compchar](const string &a, const string &b) {
      return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
                                     compchar);
    };
    return is_sorted(words.begin(), words.end(), compstring);
  }
};

int main() { return 0; }
