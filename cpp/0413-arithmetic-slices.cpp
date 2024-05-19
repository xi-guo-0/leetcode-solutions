class Solution {
public:
  int numberOfArithmeticSlices(const vector<int> &A) {
    int count = 0;
    for (int i = 0; i + 2 < A.size();) {
      if (A[i + 2] - A[i + 1] == A[i + 1] - A[i]) {
        int j = i + 3;
        while (j < A.size() && A[j] - A[j - 1] == A[i + 1] - A[i])
          j++;
        int n = j - i;
        count += ((n - 2) * (n - 1)) / 2;
        i = j - 1;
      } else {
        i++;
      }
    }
    return count;
  }
};
