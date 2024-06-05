#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    if (A.size() < 2)
      return {};

    vector<int> count(26, INT_MAX);

    for (const auto &word : A) {
      vector<int> temp_count(26, 0);
      for (char ch : word)
        temp_count[ch - 'a']++;
      for (int i = 0; i < 26; ++i)
        count[i] = min(count[i], temp_count[i]);
    }

    vector<string> result;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < count[i]; ++j) {
        result.push_back(string(1, 'a' + i));
      }
    }
    return result;
  }
};

int main() { return 0; }
