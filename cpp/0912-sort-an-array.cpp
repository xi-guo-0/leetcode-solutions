#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    return vector<int>(nums.begin(), nums.end());
  }
};

int main() { return 0; }
