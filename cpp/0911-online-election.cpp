#include <map>
#include <vector>

using namespace std;

class TopVotedCandidate {
private:
  vector<int> leaders;
  vector<int> times;

public:
  TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    int n = persons.size();
    this->times = times;

    map<int, int> count;
    int currentLeader = -1;
    int maxVotes = 0;

    for (int i = 0; i < n; ++i) {
      int person = persons[i];
      count[person]++;
      if (count[person] >= maxVotes) {
        maxVotes = count[person];
        currentLeader = person;
      }
      leaders.push_back(currentLeader);
    }
  }

  int q(int t) {
    int lo = 0, hi = times.size() - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo + 1) / 2;
      if (times[mid] <= t) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    return leaders[lo];
  }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

int main() { return 0; }
