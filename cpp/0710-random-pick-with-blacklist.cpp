#include <random>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int M;
  std::unordered_map<int, int> map;
  std::mt19937 r;

  Solution(int N, std::vector<int> &blacklist) {
    for (int b : blacklist)
      map[b] = -1;
    M = N - map.size();

    for (int b : blacklist) {
      if (b < M) {
        while (map.find(N - 1) != map.end())
          N--;
        map[b] = N - 1;
        N--;
      }
    }

    std::random_device rd;
    r.seed(rd());
  }

  int pick() {
    int p = r() % M;
    if (map.find(p) != map.end())
      return map[p];
    return p;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
