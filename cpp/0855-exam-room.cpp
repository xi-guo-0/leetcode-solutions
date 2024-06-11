#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class ExamRoom {
  int n;
  set<int> seated;

public:
  ExamRoom(int n) : n(n) {}

  int seat() {
    if (seated.empty()) {
      seated.insert(0);
      return 0;
    }

    int maxDist = *seated.begin();
    int prev = -1;
    int seat = 0;

    for (int s : seated) {
      if (prev >= 0) {
        int dist = (s - prev) / 2;
        if (dist > maxDist) {
          maxDist = dist;
          seat = prev + dist;
        }
      }
      prev = s;
    }

    if (n - 1 - *seated.rbegin() > maxDist)
      seat = n - 1;

    seated.insert(seat);
    return seat;
  }

  void leave(int p) { seated.erase(p); }
};

int main() { return 0; }
