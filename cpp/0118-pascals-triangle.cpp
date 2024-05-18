class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows <= 0) {
      return vector<vector<int>>();
    }
    vector<vector<int>> result;
    for (int i = 1; i <= numRows; i++)
      result.push_back(move(vector<int>(i, 1)));
    for (int i = 2; i < numRows; i++)
      for (int j = 1; j < i; j++)
        result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
    return result;
  }
};
