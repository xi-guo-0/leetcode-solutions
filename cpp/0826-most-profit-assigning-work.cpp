#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    vector<pair<int, int>> jobs;
    for (size_t i = 0; i < difficulty.size(); ++i) {
      jobs.emplace_back(difficulty[i], profit[i]);
    }
    ranges::sort(jobs);
    for (size_t i = 1; i < jobs.size(); ++i) {
      jobs[i].second = max(jobs[i].second, jobs[i - 1].second);
    }
    int ans = 0;
    for (const auto &w : worker) {
      auto it = upper_bound(jobs.begin(), jobs.end(),
                            pair<int, int>{w, numeric_limits<int>::max()});
      if (it != jobs.begin()) {
        ans += prev(it)->second;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<int> difficulty = {85, 47, 57};
  vector<int> profit = {24, 66, 99};
  vector<int> worker = {40, 25, 25};
  sol.maxProfitAssignment(difficulty, profit, worker);
  return 0;
}
