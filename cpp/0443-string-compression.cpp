class Solution {
public:
  int compress(vector<char> &chars) {
    int index = 0;
    stack<int> sk;
    for (int i = 0; i < chars.size();) {
      chars[index++] = chars[i];
      if (i + 1 == chars.size() || chars[i] != chars[i + 1]) {
        i += 1;
      } else {
        int j = i + 1;
        while (j < chars.size() && chars[i] == chars[j])
          j++;
        int count = j - i;
        while (count != 0) {
          sk.push(count % 10);
          count /= 10;
        }
        while (!sk.empty()) {
          chars[index++] = '0' + sk.top();
          sk.pop();
        }
        i = j;
      }
    }
    return index;
  }
};
