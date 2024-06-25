#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> prisonAfterNDays(vector<int> &cells, int N) {
    unordered_map<int, int> seen;

    int state = 0;
    for (int i = 0; i < 8; ++i) {
      if (cells[i] > 0)
        state ^= 1 << i;
    }

    while (N > 0) {
      if (seen.count(state)) {
        N %= seen[state] - N;
      }
      seen[state] = N;

      if (N >= 1) {
        N--;
        state = nextDay(state);
      }
    }

    vector<int> ans(8);
    for (int i = 0; i < 8; ++i) {
      if ((state >> i) & 1) {
        ans[i] = 1;
      }
    }

    return ans;
  }

  int nextDay(int state) {
    int ans = 0;

    for (int i = 1; i <= 6; ++i) {
      if (((state >> (i - 1)) & 1) == ((state >> (i + 1)) & 1)) {
        ans ^= 1 << i;
      }
    }

    return ans;
  }
};

int main() { return 0; }
