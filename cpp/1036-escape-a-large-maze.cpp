#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct VectorHash {
  size_t operator()(const vector<int> &v) const {
    return hash<long long>()(static_cast<long long>(v[0]) * 20001 + v[1]);
  }
};

class Solution {
public:
  bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source,
                        vector<int> &target) {
    unordered_set<vector<int>, VectorHash> blockedSet(blocked.begin(),
                                                      blocked.end());
    // The maximum area that can be enclosed by the blocked cells
    int maxArea = blocked.size() * (blocked.size() - 1) / 2;
    return bfs(blockedSet, source, target, maxArea) &&
           bfs(blockedSet, target, source, maxArea);
  }

private:
  bool bfs(const unordered_set<vector<int>, VectorHash> &blocked,
           vector<int> start, vector<int> end, int maxArea) {
    if (blocked.empty())
      return true;

    unordered_set<vector<int>, VectorHash> visited;
    queue<vector<int>> q;
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    q.push(start);
    visited.insert(start);

    int steps = 0;
    while (!q.empty()) {
      auto curr = q.front();
      q.pop();
      steps++;

      // If steps exceed maxArea, it's unlikely to be blocked
      if (steps > maxArea)
        return true;

      for (auto &dir : directions) {
        vector<int> next = {curr[0] + dir[0], curr[1] + dir[1]};
        if (next == end)
          return true;
        if (next[0] >= 0 && next[1] >= 0 && next[0] < 1e6 && next[1] < 1e6 &&
            blocked.find(next) == blocked.end() &&
            visited.find(next) == visited.end()) {
          q.push(next);
          visited.insert(next);
        }
      }
    }
    return false;
  }
};

int main() { return 0; }