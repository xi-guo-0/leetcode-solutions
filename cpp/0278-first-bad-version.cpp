// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) { return lower(1, n); }

  int lower(int left, int right) {
    if (left == right) {
      return left;
    } else {
      auto sum = static_cast<int64_t>(left) + right;
      auto mid = static_cast<int>(sum / 2);
      bool cur = isBadVersion(mid);
      if (cur) {
        return lower(left, mid);
      } else {
        return lower(mid + 1, right);
      }
    }
  }
};
