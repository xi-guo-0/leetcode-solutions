#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  bool validateStackSequences(const vector<int> &pushed,
                              const vector<int> &popped) {
    stack<int> sk;
    auto first = pushed.cbegin();
    for (const auto ch : popped) {
      if (!sk.empty() && sk.top() == ch) {
        sk.pop();
      } else {
        while (first != pushed.cend() && *first != ch)
          sk.push(*first++);
        if (first == pushed.cend())
          return false;
        else
          first++;
      }
    }
    return first == pushed.cend();
  }
};

int main() { return 0; }
