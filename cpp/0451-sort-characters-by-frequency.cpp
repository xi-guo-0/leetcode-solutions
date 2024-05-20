class Solution {
public:
  string frequencySort(const string &s) {
    vector<pair<int, char>> frequency(128);
    generate(frequency.begin(), frequency.end(),
             [ch = 0]() mutable { return make_pair(0, ch++); });
    for (const char ch : s)
      frequency[ch].first++;
    sort(frequency.begin(), frequency.end(),
         [](const pair<int, char> &a, pair<int, char> &b) {
           return a.first != b.first ? a.first > b.first : a.second < b.second;
         });
    ostringstream os;
    for (const auto &p : frequency)
      for (int i = 0; i < p.first; i++)
        os << p.second;
    return os.str();
  }
};
