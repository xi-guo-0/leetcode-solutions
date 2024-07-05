#include <vector>

using namespace std;

class Solution {
public:
  string removeDuplicates(string s) {
    string sk;
    for (char ch : s)
      if (!sk.empty() && sk.back() == ch)
        sk.pop_back();
      else
        sk.push_back(ch);
    return sk;
  }
};

int main() { return 0; }