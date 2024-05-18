class Solution {
public:
  vector<string> fullJustify(const vector<string> &words, const int maxWidth) {
    vector<vector<string>> lines{vector<string>()};
    vector<vector<int>> line_space;
    vector<int> line_letters{0};
    vector<string> ans;
    for (const auto &word : words) {
      if (lines.back().size() + line_letters.back() + word.size() <= maxWidth) {
        lines.back().push_back(word);
        line_letters.back() += word.size();
      } else {
        if (1 < lines.back().size()) {
          int space_num = maxWidth - line_letters.back();
          int pos_cnt = lines.back().size() - 1;
          vector<int> cur_space(pos_cnt + 1, space_num / pos_cnt);
          cur_space.back() = 0;
          space_num = space_num % pos_cnt;
          for (int i = 0; i < space_num; ++i)
            ++cur_space[i];
          line_space.push_back(cur_space);
        } else {
          line_space.push_back(vector<int>{maxWidth - line_letters.back()});
        }
        lines.push_back(vector<string>{word});
        line_letters.push_back(word.size());
      }
    }
    for (int i = 0; i + 1 < lines.size(); ++i) {
      ostringstream os;
      for (int j = 0; j < lines[i].size(); ++j) {
        os << lines[i][j];
        for (int k = 0; k < line_space[i][j]; ++k)
          os << " ";
      }
      ans.push_back(os.str());
    }
    do {
      const int last_space =
          maxWidth - lines.back().size() - line_letters.back() + 1;
      ostringstream os;
      os << lines.back()[0];
      for (int j = 1; j < lines.back().size(); ++j)
        os << " " << lines.back()[j];
      for (int k = 0; k < last_space; ++k)
        os << " ";
      ans.push_back(os.str());
    } while (false);
    return ans;
  }
};
