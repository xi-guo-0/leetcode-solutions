#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCasePermutation(string S) {
    vector<string> res;
    backTracking(res, S, 0);
    return res;
  }

  void backTracking(vector<string> &res, string S, int i) {
    if (i == S.size()) {
      res.push_back(S);
      return;
    }
    if (!isalpha(S[i]))
      backTracking(res, S, i + 1);
    else {
      S[i] = tolower(S[i]);
      backTracking(res, S, i + 1);
      S[i] = toupper(S[i]);
      backTracking(res, S, i + 1);
    }
  }
};
