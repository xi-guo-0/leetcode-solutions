#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int videoStitching(vector<vector<int>> &clips, int time) {
    vector<int> maxn(time);
    int last = 0, ret = 0, pre = 0;
    for (vector<int> &it : clips) {
      if (it[0] < time) {
        maxn[it[0]] = max(maxn[it[0]], it[1]);
      }
    }
    for (int i = 0; i < time; i++) {
      last = max(last, maxn[i]);
      if (i == last) {
        return -1;
      }
      if (i == pre) {
        ret++;
        pre = last;
      }
    }
    return ret;
  }
};

int main() { return 0; }
