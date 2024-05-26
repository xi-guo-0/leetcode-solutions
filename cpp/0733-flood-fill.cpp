#include <vector>

using namespace std;

class Solution {
  int getColor(vector<vector<int>> &image, int sr, int sc) const {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[sr].size())
      return -1;
    return image[sr][sc];
  }
  void floodFillRec(vector<vector<int>> &image, int sr, int sc, int colorfrom,
                    int colorto) {
    int color = getColor(image, sr, sc);
    if (color != colorfrom || color == colorto || color == -1) {
      return;
    }
    image[sr][sc] = colorto;
    floodFillRec(image, sr + 1, sc, colorfrom, colorto);
    floodFillRec(image, sr - 1, sc, colorfrom, colorto);
    floodFillRec(image, sr, sc + 1, colorfrom, colorto);
    floodFillRec(image, sr, sc - 1, colorfrom, colorto);
  }

public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int color) {
    floodFillRec(image, sr, sc, getColor(image, sr, sc), color);
    return image;
  }
};

int main() {}
