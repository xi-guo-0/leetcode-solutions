class SummaryRanges {
public:
  SummaryRanges() {}

  void addNum(int value) {
    vector<int> newInterval{value, value};
    auto it = intervals.begin();
    while (it != intervals.end()) {
      if (newInterval[1] + 1 < (*it)[0]) {
        intervals.insert(it, newInterval);
        return;
      } else if ((*it)[1] + 1 < newInterval[0]) {
        it++;
        continue;
      } else {
        newInterval[0] = min(newInterval[0], (*it)[0]);
        newInterval[1] = max(newInterval[1], (*it)[1]);
        it = intervals.erase(it);
      }
    }
    intervals.push_back(newInterval);
  }

  vector<vector<int>> getIntervals() { return intervals; }

private:
  vector<vector<int>> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
