class Solution {
public:
  int fourSumCount(const vector<int> &A, const vector<int> &B,
                   const vector<int> &C, const vector<int> &D) {
    unordered_map<int, int> dict;
    int res = 0;
    for (int i = 0; i < A.size(); i++)
      for (int j = 0; j < B.size(); j++)
        dict[-A[i] - B[j]]++;
    for (int k = 0; k < C.size(); k++)
      for (int l = 0; l < D.size(); l++)
        res += dict[C[k] + D[l]];
    return res;
  }
};
