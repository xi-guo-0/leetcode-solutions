class Solution {
public:
  int findMinDifference(const vector<string> &timePoints) {
    auto parse = [](const string &s) {
      return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
    };
    vector<int> minues;
    int result = 1440;
    for (const auto &s : timePoints) {
      minues.push_back(parse(s));
    }
    sort(minues.begin(), minues.end());
    if (minues.size() < 2) {
      return 0;
    }
    for (int i = 1; i < minues.size(); i++)
      result = min(result, minues[i] - minues[i - 1]);
    result = min(result, minues[0] + 1440 - minues.back());
    return result;
  }
};
