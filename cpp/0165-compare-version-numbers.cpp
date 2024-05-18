class Solution {
public:
  int compareVersion(const string &version1, const string &version2) {
    int i = 0, j = 0;
    while (i < version1.size() || j < version2.size()) {
      const int a = i < version1.size() ? stoi(version1.substr(i)) : 0;
      const int b = j < version2.size() ? stoi(version2.substr(j)) : 0;
      if (a < b)
        return -1;
      else if (a > b)
        return 1;
      while (i < version1.size() && version1[i] != '.')
        i++;
      i++;
      while (j < version2.size() && version2[j] != '.')
        j++;
      j++;
    }
    return 0;
  }
};
