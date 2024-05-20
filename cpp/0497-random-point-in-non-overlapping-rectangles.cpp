#include <random>
#include <vector>

using namespace std;

class Solution {
public:
  Solution(vector<vector<int>> &rects) {
    this->rects = rects;
    int totalArea = 0;
    for (const auto &rect : rects) {
      int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
      totalArea += area;
      areas.push_back(totalArea);
    }
    random_device rd;
    rng.seed(rd());
  }

  vector<int> pick() {
    int target = uniform_int_distribution<int>(0, areas.back() - 1)(rng);
    int left = 0, right = areas.size() - 1;
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (areas[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    const auto &rect = rects[left];
    int x = uniform_int_distribution<int>(rect[0], rect[2])(rng);
    int y = uniform_int_distribution<int>(rect[1], rect[3])(rng);
    return {x, y};
  }

private:
  vector<vector<int>> rects;
  vector<int> areas;
  mt19937 rng;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
