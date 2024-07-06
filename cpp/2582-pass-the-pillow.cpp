class Solution {
public:
  int passThePillow(int n, int time) {
    int cycleLength = (n - 1) * 2;
    int remainingTime = time % cycleLength;

    if (remainingTime < n) {
      return remainingTime + 1;
    } else {
      return n - (remainingTime - n + 1);
    }
  }
};

int main() { return 0; }