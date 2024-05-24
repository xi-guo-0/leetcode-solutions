class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> result(n, 0);
    int num = 1;
    for (int i = 0; i <= k; i += 2)
      result[i] = num++;
    int tmp = k + 1;
    for (int i = 1; i <= k; i += 2)
      result[i] = tmp--;
    for (int i = k + 1; i < n; i++)
      result[i] = i + 1;
    return result;
  }
};
