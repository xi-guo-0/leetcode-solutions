#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string reverseParentheses(string s) {
    string ans;
    stack<string> stk;
    for (const auto &ch : s) {
      if (ch == '(') {
        stk.push(ans);
        ans.clear();
      } else if (ch == ')') {
        reverse(ans.begin(), ans.end());
        ans = stk.top() + ans;
        stk.pop();
      } else {
        ans.push_back(ch);
      }
    }
    return ans;
  }
};

int main() { return 0; }
