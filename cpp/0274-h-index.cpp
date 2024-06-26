class Solution {
public:
  int hIndex(vector<int> &citations) {
    sort(rbegin(citations), rend(citations));
    for (int i = 0; i < citations.size(); ++i) {
      if (citations[i] <= i) {
        return i;
      }
    }
    return citations.size();
  }
};
