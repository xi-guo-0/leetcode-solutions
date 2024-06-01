#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    int n = arr.size();
    vector<tuple<double, int, int>> fractions;
    fractions.reserve(n * (n - 1) / 2);

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        fractions.emplace_back(static_cast<double>(arr[i]) / arr[j], arr[i],
                               arr[j]);
      }
    }

    sort(fractions.begin(), fractions.end(),
         [](const auto &a, const auto &b) { return get<0>(a) < get<0>(b); });

    auto [_, numerator, denominator] = fractions[k - 1];
    return {numerator, denominator};
  }
};

int main() { return 0; }
