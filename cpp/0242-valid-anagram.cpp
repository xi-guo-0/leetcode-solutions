class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;
    char cnt[128] = {0};
    for (char ch : s)
      cnt[ch]++;
    for (char ch : t)
      cnt[ch]--;
    for (char ch : s)
      if (cnt[ch] != 0)
        return false;
    return true;
  }
};
