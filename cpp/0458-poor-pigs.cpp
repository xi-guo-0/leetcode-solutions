class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    return static_cast<int>(
        ceil(log(buckets) / log(minutesToTest / minutesToDie + 1)));
  }
};
