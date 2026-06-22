class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    int min_m = prices[0];
    for (int x : prices) {
      min_m = min(min_m, x);
      profit = max(profit, x - min_m);
    }
    return profit;
  }
};