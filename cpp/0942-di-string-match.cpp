#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> diStringMatch(string s) {
    int i = 0, j = s.size();
    vector<int> result;
    for (auto ch : s)
      if (ch == 'I')
        result.push_back(i++);
      else
        result.push_back(j--);
    result.push_back(i);
    return result;
  }
};

int main() { return 0; }
