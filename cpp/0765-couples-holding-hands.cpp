#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minSwapsCouples(vector<int> &row) {
    int ans = 0;
    for (int i = 0; i < row.size(); i += 2) {
      const int other = row[i] + ((row[i] % 2) ? -1 : 1);
      if (row[i + 1] != other) {
        int j = i + 2;
        for (; j < row.size() && row[j] != other; j++) {
        }
        swap(row[i + 1], row[j]);
        ans++;
      }
    }
    return ans;
  }
};

int main() { return 0; }
