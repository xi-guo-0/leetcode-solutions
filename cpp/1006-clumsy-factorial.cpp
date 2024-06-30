class Solution {
public:
  int clumsy(int n) {
    static const int a[] = {1, 2, 2, -1};
    return n > 4 ? n + a[n % 4] : (n > 2 ? n + 3 : n);
  }
};

int main() { return 0; }
