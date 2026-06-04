class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }
        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int t = 0; t <= k; t++) {
            dp[t][0] = 0;
            dp[t][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int t = k; t >= 1; t--) {
                dp[t][0] = max(dp[t][0],
                               dp[t][1] + prices[i]);
                dp[t][1] = max(dp[t][1],
                               dp[t - 1][0] - prices[i]);
            }
        }
        return dp[k][0];
    }
};