class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u',
                               'A', 'E', 'I', 'O', 'U'};
    int n = s.size();
    vector<bool> is_vowel(n, false);
    vector<char> par;
    for (int i = n - 1; 0 <= i; --i) {
      if (vowels.count(s[i])) {
        is_vowel[i] = true;
        par.push_back(s[i]);
      }
    }
    for (int i = 0, j = 0; i < n, j < par.size(); ++i) {
      if (is_vowel[i]) {
        s[i] = par[j];
        ++j;
      }
    }
    return s;
  }
};
