#include <cstdint>
#include <limits>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    using T = int64_t;
    T totalSum = 0;
    T count = 0;
    auto positiveMin = numeric_limits<T>::max();
    auto negativeMax = numeric_limits<T>::min();

    for (int nodeValue : nums) {
      T nodeValAfterOperation = nodeValue ^ k;
      totalSum += nodeValue;
      T netChange = nodeValAfterOperation - nodeValue;

      (netChange > 0) ? (positiveMin = min(positiveMin, netChange),
                         totalSum += netChange, ++count)
                      : negativeMax = max(negativeMax, netChange);
    }

    return (count % 2 == 0)
               ? totalSum
               : max(totalSum - positiveMin, totalSum + negativeMax);
  }
};
