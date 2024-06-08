#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> largeGroupPositions(const string &s) {
    vector<vector<int>> result;
    for (int i = 0; i < s.size();) {
      int j = i + 1;
      while (j < s.size() && s[i] == s[j])
        j++;
      if (j - i > 2) {
        result.push_back(std::move(vector<int>{i, j - 1}));
      }
      i = j;
    }
    return result;
  }
};

int main() { return 0; }
