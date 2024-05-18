#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string &s) {
    int c2i[128]{};
    c2i['A'] = 0;
    c2i['C'] = 1;
    c2i['G'] = 2;
    c2i['T'] = 3;
    const char i2c[] = {'A', 'C', 'G', 'T'};
    std::unordered_map<int, int> map;
    const int len = 10;
    const int mask = 0xFFFFF;
    int num = 0;

    for (int i = 0; i < len && i < s.size(); ++i) {
      num = ((num << 2) | c2i[s[i]]) & mask;
    }
    map[num] = 1;

    for (int i = len; i < s.size(); ++i) {
      num = ((num << 2) | c2i[s[i]]) & mask;
      map[num]++;
    }

    std::vector<std::string> ans;
    for (const auto &[key, count] : map) {
      if (count > 1) {
        std::string chs(len, ' ');
        int key_copy = key;
        for (int i = len - 1; i >= 0; --i) {
          chs[i] = i2c[key_copy & 0x3];
          key_copy >>= 2;
        }
        ans.push_back(chs);
      }
    }
    return ans;
  }
};

int main() { return 0; }
