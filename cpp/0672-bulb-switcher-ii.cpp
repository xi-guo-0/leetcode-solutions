class Solution {
public:
  int flipLights(int n, int m) {
    int result = 0;
    n = min(n, 3);
    switch (m) {
    case 0:
      result = 1;
      break;
    case 1:
      result = vector<int>({2, 3, 4})[n - 1];
      break;
    case 2:
      result = vector<int>({2, 4, 7})[n - 1];
      break;
    default:
      result = vector<int>({2, 4, 8})[n - 1];
      break;
    }
    return result;
  }
};
