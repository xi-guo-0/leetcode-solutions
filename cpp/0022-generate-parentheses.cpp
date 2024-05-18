#include <string>
#include <vector>

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0)
      return vector<string>(1, "");
    else if (n == 1)
      return vector<string>(1, "()");
    vector<string> ans;
    for (int i = 0; i < n; i++)
      for (auto inner : generateParenthesis(i))
        for (auto outer : generateParenthesis(n - i - 1))
          ans.push_back("(" + inner + ")" + outer);
    return ans;
  }
};
