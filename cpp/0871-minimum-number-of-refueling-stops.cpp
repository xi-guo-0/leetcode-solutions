#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
    int stops = 0;
    long long currentFuel = startFuel;
    int currentPos = 0;
    priority_queue<int> pq;

    for (const auto &station : stations) {
      int pos = station[0];
      int fuel = station[1];

      while (currentPos + currentFuel < pos) {
        if (pq.empty())
          return -1;
        currentFuel += pq.top();
        pq.pop();
        stops++;
      }

      currentFuel -= pos - currentPos;
      currentPos = pos;
      pq.push(fuel);
    }

    while (currentPos + currentFuel < target) {
      if (pq.empty())
        return -1;
      currentFuel += pq.top();
      pq.pop();
      stops++;
    }

    return stops;
  }
};

int main() { return 0; }
