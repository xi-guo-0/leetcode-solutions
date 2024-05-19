class Solution {
public:
  int firstUniqChar(string s) {
    int counts[26] = {0};
    for (auto ch : s)
      counts[tolower(ch) - 'a']++;
    for (int i = 0; i < s.size(); i++)
      if (counts[tolower(s[i]) - 'a'] == 1)
        return i;
    return -1;
  }
};
