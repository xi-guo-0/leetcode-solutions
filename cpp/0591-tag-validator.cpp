#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string code) {
    stack<string> stk;

    for (size_t i = 0; i < code.size();) {
      if (i > 0 && stk.empty())
        return false;
      if (code.substr(i, 9) == "<![CDATA[") {
        size_t j = i + 9;
        i = code.find("]]>", j);
        if (i == string::npos)
          return false;
        i += 3;
      } else if (code[i] == '<') {
        if (i + 1 < code.size() && code[i + 1] == '/') {
          size_t j = i + 2;
          i = code.find('>', j);
          if (i == string::npos || i == j || i - j > 9)
            return false;
          string tagName = code.substr(j, i - j);
          if (stk.empty() || stk.top() != tagName)
            return false;
          stk.pop();
          i++;
        } else {
          size_t j = i + 1;
          i = code.find('>', j);
          if (i == string::npos || i == j || i - j > 9)
            return false;
          string tagName = code.substr(j, i - j);
          for (char c : tagName) {
            if (!isupper(c))
              return false;
          }
          stk.push(tagName);
        }
      } else {
        i++;
      }
    }

    return stk.empty();
  }
};
