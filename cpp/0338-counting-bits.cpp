class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> v;
    for (int i = 0; i <= num; i++) {
      bitset<32> b(i);
      v.push_back(b.count());
    }
    return v;
  }
};
