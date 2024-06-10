#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  bool canVisitAllRooms(const vector<vector<int>> &rooms) {
    if (rooms.size() == 0)
      return true;
    const int n = rooms.size();
    vector<bool> visited(n, false);
    visited.front() = true;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      const int i = q.front();
      q.pop();
      for (const int j : rooms[i]) {
        if (!visited[j]) {
          visited[j] = true;
          q.push(j);
        }
      }
    }
    bool res = true;
    for (const bool b : visited)
      res = res && b;
    return res;
  }
};

int main() { return 0; }
