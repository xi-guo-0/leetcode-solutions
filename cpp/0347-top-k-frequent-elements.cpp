class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> times;
    for (auto n : nums)
      if (times.find(n) != times.end())
        times[n]++;
      else
        times[n] = 1;
    vector<pair<int, int>> counts(times.begin(), times.end());
    sort(counts.begin(), counts.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
           return a.second > b.second;
         });
    vector<int> result;
    for (int i = 0; i < k; i++)
      result.push_back(counts[i].first);
    return result;
  }
};
