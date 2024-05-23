class Solution {
public:
  vector<vector<string>> findDuplicate(vector<string> &paths) {
    map<string, int> classification;
    vector<vector<string>> result;
    int index = 0;

    for (const auto &path : paths) {
      auto vs = split(path);
      for (int i = 1; i < vs.size(); i++) {
        string con = content(vs[i]);
        if (classification.find(con) != classification.end()) {
          result[classification[con]].push_back(vs[0] + "/" + name(vs[i]));
        } else {
          classification[con] = index++;
          result.push_back(vector<string>{vs[0] + "/" + name(vs[i])});
        }
      }
    }
    result.erase(
        remove_if(result.begin(), result.end(),
                  [](const vector<string> &a) { return a.size() < 2; }),
        result.end());
    return result;
  }

private:
  static vector<string> split(const string &s) {
    vector<string> result;
    const char ch = ' ';
    int i = 0;
    for (int j = 0; j < s.size(); j++)
      if (s[j] == ch) {
        result.push_back(s.substr(i, j - i));
        i = j + 1;
      }
    if (i < s.size())
      result.push_back(s.substr(i, s.size() - i));
    return result;
  }

  static string content(const string &s) {
    int j = s.size() - 1;
    int i = j;
    while (s[i] != '(')
      i--;
    return s.substr(i + 1, j - i - 1);
  }

  static string name(const string &s) {
    return s.substr(0, s.find_first_of('('));
  }
};
