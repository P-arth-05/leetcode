class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();

        int next = 1;      // dp[n]
        int next2 = 0;     // dp[n+1]
        int curr = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '0') {
                curr = 0;
            }
            else {

                curr = next;

                if (i + 1 < n &&
                    (s[i] == '1' ||
                    (s[i] == '2' && s[i + 1] <= '6')))
                    curr += next2;
            }

            next2 = next;
            next = curr;
        }

        return next;
    }
};