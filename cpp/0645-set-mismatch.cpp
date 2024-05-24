class Solution {
public:
  vector<int> findErrorNums(vector<int> &nums) {
    int n = nums.size();
    vector count(n, 0);
    vector<int> result(2, 0);
    for (const auto i : nums)
      count[i - 1]++;
    for (int i = 0; i < count.size(); i++)
      if (count[i] == 2)
        result[0] = i + 1;
      else if (count[i] == 0)
        result[1] = i + 1;
    return result;
  }
};
