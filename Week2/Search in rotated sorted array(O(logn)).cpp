class Solution {
 public:
  int search(vector<int>& a, int target) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (a[mid] == target) return mid;
      if (a[l] <= a[mid]) {  // left half is sorted
        if (a[l] <= target && target < a[mid])
          r = mid - 1;
        else
          l = mid + 1;
      } else {  // right half is sorted
        if (a[mid] < target && target <= a[r])
          l = mid + 1;
        else
          r = mid - 1;
      }
    }
    return -1;
  }
};