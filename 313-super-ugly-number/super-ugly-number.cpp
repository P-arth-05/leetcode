class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<long long> dp(n);
        dp[0] = 1;
        vector<int> idx(m, 0);

        for (int i = 1; i < n; i++) {
            long long nxt = LLONG_MAX;
            for (int j = 0; j < m; j++)
                nxt = min(nxt, dp[idx[j]] * 1LL * primes[j]);
            dp[i] = nxt;
            for (int j = 0; j < m; j++)
                if (dp[idx[j]] * 1LL * primes[j] == nxt)
                    idx[j]++;
        }
        return dp[n - 1];
    }
};