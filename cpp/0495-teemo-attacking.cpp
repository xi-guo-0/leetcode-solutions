class Solution {
public:
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    const vector<int> &t = timeSeries;
    const int d = duration;
    int ans = duration;
    for (int i = 1; i < t.size(); ++i) {
      if (t[i] - t[i - 1] < d) {
        ans += t[i] - t[i - 1];
      } else {
        ans += d;
      }
    }
    return ans;
  }
};
