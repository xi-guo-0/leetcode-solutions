#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    stable_sort(logs.begin(), logs.end(), [](const string &a, const string &b) {
      const int pa = a.find_first_of(' ');
      const int pb = b.find_first_of(' ');
      const bool a_is_alpha = isalpha(a[pa + 1]);
      const bool b_is_alpha = isalpha(b[pb + 1]);
      if (a_is_alpha && b_is_alpha) {
        const string a_words(a.substr(pa + 1));
        const string b_words(b.substr(pb + 1));
        if (a_words == b_words) {
          return a.substr(0, pa) < b.substr(0, pb);
        } else {
          return a_words < b_words;
        }
      } else if (a_is_alpha) {
        return true;
      }
      return false;
    });
    return logs;
  }
};

int main() { return 0; }
