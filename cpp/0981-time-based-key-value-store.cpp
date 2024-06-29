#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class TimeMap {
public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp) {
    if (!mp.count(key))
      return "";
    int l = 0, r = mp[key].size();
    while (l < r) {
      int m = (l + r) / 2;
      if (mp[key][m].first > timestamp)
        r = m;
      else
        l = m + 1;
    }
    r--;
    if (r < 0)
      return "";
    return mp[key][r].second;
  }

private:
  unordered_map<string, vector<pair<int, string>>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() { return 0; }
