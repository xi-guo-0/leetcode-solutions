class Solution {
public:
  int countSegments(string s) {
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char ch) { return isspace(ch) ? ' ' : '_'; });
    istringstream is(s);
    string t;
    int count = 0;
    while (is >> t)
      count++;
    return count;
  }
};
