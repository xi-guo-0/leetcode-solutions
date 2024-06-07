#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int racecar(int target) {
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    queue<tuple<int, int, int>> q;
    q.push({0, 1, 0});

    unordered_set<pair<int, int>, hash_pair> visited;
    visited.insert({0, 1});

    while (!q.empty()) {
      auto [pos, speed, steps] = q.front();
      q.pop();

      if (pos == target) {
        return steps;
      }

      int newPos = pos + speed;
      int newSpeed = speed * 2;
      if (abs(newPos) <= target * 2 &&
          visited.insert({newPos, newSpeed}).second) {
        q.push({newPos, newSpeed, steps + 1});
      }

      newSpeed = speed > 0 ? -1 : 1;
      if (visited.insert({pos, newSpeed}).second) {
        q.push({pos, newSpeed, steps + 1});
      }
    }

    return -1;
  }

private:
  struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
      auto hash1 = hash<T1>{}(p.first);
      auto hash2 = hash<T2>{}(p.second);
      return hash1 ^ hash2;
    }
  };
};

int main() { return 0; }
