class Solution {
public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        vector<int> arr(n + 2, 1);

        for (int i = 0; i < n; i++)
            arr[i + 1] = nums[i];

        n += 2;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 2; len < n; len++) {

            for (int left = 0; left + len < n; left++) {

                int right = left + len;

                for (int k = left + 1; k < right; k++) {

                    dp[left][right] = max(
                        dp[left][right],
                        dp[left][k]
                        + dp[k][right]
                        + arr[left] * arr[k] * arr[right]
                    );
                }
            }
        }

        return dp[0][n - 1];
    }
};