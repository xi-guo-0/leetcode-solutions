class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int m = matrix.size();
    int n = matrix[0].size();
    int maxSum = INT_MIN;

    for (int left = 0; left < n; ++left) {
      vector<int> prefixSum(m, 0);

      for (int right = left; right < n; ++right) {
        for (int i = 0; i < m; ++i) {
          prefixSum[i] += matrix[i][right];
        }

        set<int> prefixSumsSet;
        prefixSumsSet.insert(0);
        int currentSum = 0;

        for (int sum : prefixSum) {
          currentSum += sum;
          auto it = prefixSumsSet.lower_bound(currentSum - k);
          if (it != prefixSumsSet.end()) {
            maxSum = max(maxSum, currentSum - *it);
          }
          prefixSumsSet.insert(currentSum);
        }
      }
    }

    return maxSum;
  }
};
