#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sumEvenAfterQueries(vector<int> &nums,
                                  vector<vector<int>> &queries) {
    vector<int> result;
    for (int i = 0; i < queries.size(); i++) {
      int index = queries[i][1];
      nums[index] += queries[i][0];
      result.push_back(
          accumulate(nums.begin(), nums.end(), 0, [](int a, int b) {
            int x = a & 0x1 ? 0 : a;
            int y = b & 0x1 ? 0 : b;
            return x + y;
          }));
    }
    return result;
  }
};

int main() { return 0; }
