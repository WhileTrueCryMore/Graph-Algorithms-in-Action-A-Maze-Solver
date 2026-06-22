class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1;
    int r = *max_element(piles.begin(), piles.end());

    while (l < r) {
      int mid = l + (r - l) / 2;

      if (isPossible(piles, h, mid))
        r = mid;
      else
        l = mid + 1;
    }

    return l;
  }

  bool isPossible(const vector<int>& piles, int h, int k) {
    long long hours = 0;

    for (int x : piles)
      hours += (x + k - 1) / k;

    return hours <= h;
  }
};