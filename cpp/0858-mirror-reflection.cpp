class Solution {
public:
  int mirrorReflection(int p, int q) {
    int g = gcd(p, q);
    p /= g;
    q /= g;
    p %= 2;
    q %= 2;
    if (p == 1 && q == 1) {
      return 1;
    }
    return p == 1 ? 0 : 2;
  }

private:
  static int gcd(int a, int b) {
    int r = 0;
    while (b != 0) {
      r = a % b;
      a = b;
      b = r;
    }
    return a;
  }
};

int main() { return 0; }
