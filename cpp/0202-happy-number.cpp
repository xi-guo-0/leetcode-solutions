class Solution {
public:
  bool isHappy(int n) {
    set<int> dict;
    while (n != 1 && !dict.count(n)) {
      dict.insert(n);
      int sum = 0;
      while (n != 0) {
        sum += (n % 10) * (n % 10);
        n /= 10;
      }
      n = sum;
    }
    return n == 1;
  }
};
