class Solution {
public:
  bool validUtf8(const vector<int> &data) {
    for (int i = 0; i < data.size();) {
      int tmp = data[i];
      int cnt = 0;
      for (int i = 0; i < 8 && tmp & 0x80; i++) {
        tmp <<= 1;
        cnt++;
      }
      int j = cnt == 0 ? i + 1 : i + cnt;
      if (cnt == 1 || cnt > 4)
        return false;
      if (j > data.size())
        return false;
      if (cnt != 0) {
        for (int k = i + 1; k < j; k++) {
          tmp = data[k];
          tmp = tmp & 0xc0;
          tmp = tmp ^ 0x80;
          if (tmp != 0)
            return false;
        }
      }
      i = j;
    }
    return true;
  }
};
