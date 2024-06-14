#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    int ans = 0;
    sort(people.begin(), people.end());
    for (auto l = people.begin(), r = prev(people.end()); l <= r;) {
      if (*l + *r <= limit)
        ++l;
      --r, ++ans;
    }
    return ans;
  }
};

int main() { return 0; }
