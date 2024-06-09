#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  struct node {
    int index;
    string source;
    string target;
  };
  static bool comp(const node &a, const node &b) { return a.index < b.index; }
  string findReplaceString(const string &S, const vector<int> &indexes,
                           const vector<string> &sources,
                           const vector<string> &targets) {
    ostringstream res;
    int len = indexes.size();
    vector<node> record;
    for (int i = 0; i < len; i++) {
      record.push_back({indexes[i], sources[i], targets[i]});
    }
    sort(record.begin(), record.end(), comp);
    int start = 0;
    for (int i = 0; i < len; i++) {
      res << S.substr(start, record[i].index - start);
      start += record[i].index - start;
      if (S.find(record[i].source, record[i].index) == record[i].index) {
        res << record[i].target;
        start += record[i].source.size();
      }
    }
    res << S.substr(start);
    return res.str();
  }
};

int main() { return 0; }
