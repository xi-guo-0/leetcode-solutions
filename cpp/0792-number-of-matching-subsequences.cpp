#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int numMatchingSubseq(const string &S, const vector<string> &words) {
    if (S.empty() || words.empty())
      return 0;

    array<int, 26> alpha = {0};
    vector<array<int, 26>> aim(S.size(), alpha);

    for (int i = S.size() - 1; i >= 0; --i) {
      aim[i] = alpha;
      alpha[S[i] - 'a'] = i;
    }

    int ans = 0;
    for (const auto &word : words) {
      int i = 0, k = 0;
      while (k < word.size() && i < S.size()) {
        if (S[i] == word[k]) {
          ++i;
          ++k;
        } else {
          if (aim[i][word[k] - 'a'] == 0)
            break;
          else
            i = aim[i][word[k] - 'a'];
        }
      }
      if (k == word.size())
        ++ans;
    }
    return ans;
  }
};

int main() { return 0; }
