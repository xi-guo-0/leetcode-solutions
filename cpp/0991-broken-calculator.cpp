class Solution {
public:
  int brokenCalc(int startValue, int target) {
    int res = 0;
    while (startValue < target) {
      res++;
      if (target & 0x1)
        target++;
      else
        target /= 2;
    }
    return startValue - target + res;
  }
};

int main() { return 0; }
