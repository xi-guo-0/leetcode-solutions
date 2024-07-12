#include <string>

using namespace std;

class Solution {
public:
  int maximumGain(string s, int x, int y) {
    string first = x > y ? "ab" : "ba";
    int firstScore = max(x, y);
    string second = x > y ? "ba" : "ab";
    int secondScore = min(x, y);

    auto removeSubstrings = [&](string &s, string target, int score) -> int {
      int totalScore = 0, j = 0;
      for (int i = 0; i < s.size(); ++i) {
        s[j] = s[i];
        if (j > 0 && s[j - 1] == target[0] && s[j] == target[1]) {
          j--;
          totalScore += score;
        } else {
          j++;
        }
      }
      s.resize(j);
      return totalScore;
    };

    int totalScore = 0;
    totalScore += removeSubstrings(s, first, firstScore);
    totalScore += removeSubstrings(s, second, secondScore);

    return totalScore;
  }
};

int main() { return 0; }
