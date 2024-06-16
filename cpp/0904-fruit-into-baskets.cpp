#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int ans = 0, i = 0;
    unordered_map<int, int> dict;
    for (int j = 0; j < fruits.size(); ++j) {
      ++dict[fruits[j]];
      while (3 <= dict.size()) {
        --dict[fruits[i]];
        if (dict[fruits[i]] == 0) {
          dict.erase(fruits[i]);
        }
        ++i;
      }
      ans = max(ans, j - i + 1);
    }
    return ans;
  }
};

int main() { return 0; }
