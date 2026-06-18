class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> v;
    int idx = k;
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[i] >= nums[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(i);
    }
    v.push_back(nums[dq.front()]);
    while (idx < n) {
      while (!dq.empty() && dq.front() < idx - k + 1) {
        dq.pop_front();
      }
      while (!dq.empty() && nums[idx] >= nums[dq.back()]) {
        dq.pop_back();
      }
      dq.push_back(idx);
      v.push_back(nums[dq.front()]);
      idx++;
    }
    return v;
  }
};