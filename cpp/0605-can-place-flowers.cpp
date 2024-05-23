class Solution {
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n) {
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    int cnt = 0;
    for (int i = 2; i < flowerbed.size(); i++)
      if (!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i - 2]) {
        flowerbed[i - 1] = 1;
        cnt++;
      }
    return cnt >= n;
  }
};
