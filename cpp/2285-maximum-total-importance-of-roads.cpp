#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
  long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<long long> degree(n, 0);
    for (const auto &road : roads) {
      degree[road[0]] += 1;
      degree[road[1]] += 1;
    }
    ranges::sort(degree);
    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
      sum += (i + 1) * degree[i];
    }
    return sum;
  }
};

int main() {
  int n = 5;
  vector<vector<int>> roads{{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
  return 0;
}
