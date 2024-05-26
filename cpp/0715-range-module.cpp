#include <cassert>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class RangeModule {
public:
  RangeModule() {}

  void addRange(int left, int right) {
    auto it = intervals.lower_bound(left);
    if (it != intervals.begin() && prev(it)->second >= left) {
      --it;
    }

    while (it != intervals.end() && it->first <= right) {
      left = min(left, it->first);
      right = max(right, it->second);
      it = intervals.erase(it);
    }

    intervals[left] = right;
  }

  bool queryRange(int left, int right) {
    auto it = intervals.upper_bound(left);
    if (it == intervals.begin())
      return false;
    --it;
    return it->second >= right;
  }

  void removeRange(int left, int right) {
    auto it = intervals.lower_bound(left);
    if (it != intervals.begin() && prev(it)->second > left) {
      --it;
    }

    vector<pair<int, int>> toAdd;

    while (it != intervals.end() && it->first < right) {
      if (it->first < left) {
        toAdd.emplace_back(it->first, left);
      }
      if (it->second > right) {
        toAdd.emplace_back(right, it->second);
      }
      it = intervals.erase(it);
    }

    for (const auto &p : toAdd) {
      intervals[p.first] = p.second;
    }
  }

private:
  map<int, int> intervals;
};

/*
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second < b.first;
};

template <class ForwardIt, class T>
std::pair<ForwardIt, ForwardIt> query(ForwardIt first, ForwardIt last,
                                      T value) {
  return make_pair(lower_bound(first, last, value, comp),
                   upper_bound(first, last, value, comp));
}

class RangeModule {
public:
  RangeModule() {}

  void addRange(int left, int right) {
    auto newInterval = make_pair(left, right);
    auto [it, jt] = query(intervals.begin(), intervals.end(), newInterval);

    if (jt == intervals.begin()) {
      intervals.insert(intervals.begin(), newInterval);
    } else if (it == intervals.end()) {
      intervals.push_back(newInterval);
    } else {
      newInterval.first = min(newInterval.first, it->first);
      newInterval.second =
          max(newInterval.second,
              (jt == intervals.begin() ? it : prev(jt))->second);
      intervals.erase(it, jt);
      intervals.insert(it, newInterval);
    }
  }

  bool queryRange(int left, int right) {
    auto newInterval = make_pair(left, right);
    auto [it, jt] = query(intervals.begin(), intervals.end(), newInterval);
    return it != intervals.end() && jt != intervals.begin() &&
           it->first <= left && right <= it->second;
  }

  void removeRange(int left, int right) {
    auto newInterval = make_pair(left, right);
    auto [it, jt] = query(intervals.begin(), intervals.end(), newInterval);
    if (it != intervals.end() && jt != intervals.begin()) {
      auto oldInterval = make_pair(it->first, prev(jt)->second);
      intervals.erase(it, jt);
      if (newInterval.second < oldInterval.second) {
        intervals.insert(it, make_pair(newInterval.second, oldInterval.second));
      }
      if (oldInterval.first < newInterval.first) {
        intervals.insert(it, make_pair(oldInterval.first, newInterval.first));
      }
    }
  }

private:
  vector<pair<int, int>> intervals;
};
*/

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */

int main() {
  RangeModule range_module;
  range_module.addRange(2, 6);
  range_module.addRange(2, 8);
  range_module.addRange(4, 7);
  range_module.queryRange(0, 0);
  range_module.removeRange(1, 10);
  range_module.queryRange(0, 0);
  return 0;
}
