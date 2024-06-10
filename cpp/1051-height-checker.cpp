#include <vector>

using namespace std;

class Solution {
public:
  int heightChecker(vector<int> &heights) {
    vector<int> ordered(heights.begin(), heights.end());
    sort(ordered.begin(), ordered.end());
    int count = 0;
    for (int i = 0; i < heights.size(); i++)
      count += ordered[i] != heights[i];
    return count;
  }
};

int main() { return 0; }
