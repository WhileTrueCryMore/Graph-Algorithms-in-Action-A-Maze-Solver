class Solution {
 public:
  void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
      largest = left;

    if (right < n && nums[right] > nums[largest])
      largest = right;

    if (largest != i) {
      swap(nums[i], nums[largest]);
      heapify(nums, n, largest);
    }
  }

  void buildHeap(vector<int>& nums) {
    int n = nums.size();

    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(nums, n, i);
  }

  int findKthLargest(vector<int>& nums, int k) {
    buildHeap(nums);

    int n = nums.size();

    for (int i = 1; i < k; i++) {
      swap(nums[0], nums[n - 1]);
      n--;
      heapify(nums, n, 0);
    }

    return nums[0];
  }
};