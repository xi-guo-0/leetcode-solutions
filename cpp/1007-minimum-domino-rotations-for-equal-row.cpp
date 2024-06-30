#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    int n = tops.size();
    int rotations = check(tops[0], bottoms, tops, n);
    if (rotations != -1 || tops[0] == bottoms[0])
      return rotations;
    else
      return check(bottoms[0], bottoms, tops, n);
  }

  int check(int x, vector<int> &tops, vector<int> &bottoms, int n) {

    int rotations_a = 0, rotations_b = 0;
    for (int i = 0; i < n; i++) {

      if (tops[i] != x && bottoms[i] != x)
        return -1;

      else if (tops[i] != x)
        rotations_a++;

      else if (bottoms[i] != x)
        rotations_b++;
    }

    return min(rotations_a, rotations_b);
  }
};

int main() { return 0; }
