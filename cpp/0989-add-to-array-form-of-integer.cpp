#include <vector>

using namespace std;

class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    num[num.size() - 1] += k;
    for (int i = num.size() - 1; 0 < i; i--) {
      if (9 < num[i]) {
        num[i - 1] += num[i] / 10;
        num[i] %= 10;
      }
    }
    while (9 < num[0]) {
      num.insert(num.begin(), num[0] / 10);
      num[1] %= 10;
    }
    return num;
  }
};

int main() { return 0; }
