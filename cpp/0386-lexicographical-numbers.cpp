class Solution {
public:
  vector<int> lexicalOrder(int n) {
    stack<int> s;
    vector<int> result;
    for (int i = 9; 0 < i; i--)
      s.push(i);
    while (!s.empty()) {
      const int i = s.top();
      s.pop();
      if (i <= n)
        result.push_back(i);
      const int m = i * 10;
      for (int j = 9; 0 <= j; j--)
        if (m + j <= n)
          s.push(m + j);
    }

    return result;
  }
};
