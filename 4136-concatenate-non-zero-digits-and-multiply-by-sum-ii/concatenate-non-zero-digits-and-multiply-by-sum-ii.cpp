class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> digit;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                digit.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = digit.size();

        vector<long long> prefSum(m + 1, 0);
        vector<long long> prefNum(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digit[i];
            prefNum[i + 1] = (prefNum[i] * 10 + digit[i]) % MOD;
            pow10[i + 1] = (pow10[i] * 10) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[R + 1] - prefSum[L];

            int len = R - L + 1;

            long long x =
                (prefNum[R + 1] -
                 prefNum[L] * pow10[len] % MOD +
                 MOD) % MOD;

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};