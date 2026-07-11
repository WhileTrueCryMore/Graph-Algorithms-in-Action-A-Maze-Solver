class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int r = image.size();
    int c = image[0].size();
    int init = image[sr][sc];
    if (color == init) {
      return image;
    }
    flood(image, sr, sc, init, color, r, c);
    return image;
  }
  void flood(vector<vector<int>>& image, int a, int b, int init, int color, int r, int c) {
    if (a < 0 || b < 0 || a >= r || b >= c) {
      return;
    }
    if (image[a][b] != init) {
      return;
    }
    image[a][b] = color;
    flood(image, a + 1, b, init, color, r, c);
    flood(image, a - 1, b, init, color, r, c);
    flood(image, a, b + 1, init, color, r, c);
    flood(image, a, b - 1, init, color, r, c);
  }
};