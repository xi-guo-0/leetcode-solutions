#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthLongestPath(string input) {

    stringstream ss(input);
    string line;
    stack<int> st;
    st.push(0);
    int maxLen = 0;

    while (getline(ss, line, '\n')) {
      int level = line.find_last_of('\t') + 1;
      while (level + 1 < st.size())
        st.pop();
      int len = line.substr(level).size();
      if (line.find('.') != string::npos) {
        maxLen = max(maxLen, st.top() + len);
      } else {
        st.push(st.top() + len + 1);
      }
    }

    return maxLen;
  }
};
