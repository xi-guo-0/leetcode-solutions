class Solution {
public:
  int findTheWinner(int n, int k) { return josephus(n, k); }

private:
  int josephus(int n, int k) {
    if (n == 1)
      return 1;
    else
      return (josephus(n - 1, k) + k - 1) % n + 1;
  }
};

int main() { return 0; }
