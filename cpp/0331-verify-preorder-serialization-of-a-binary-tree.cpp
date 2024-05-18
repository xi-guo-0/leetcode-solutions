#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValidSerialization(string preorder) {
    std::stack<std::string> stack;
    std::istringstream iss(preorder);
    std::string node;

    while (std::getline(iss, node, ',')) {
      while (!stack.empty() && stack.top() == "#" && node == "#") {
        stack.pop();
        if (stack.empty())
          return false;
        stack.pop();
      }
      stack.push(node);
    }

    return stack.size() == 1 && stack.top() == "#";
  }
};

int main() {
  Solution().isValidSerialization("9,9,#,#,9,#,#");
  return 0;
}
