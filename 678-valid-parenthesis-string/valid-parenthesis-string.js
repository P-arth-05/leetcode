/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    let n = s.length;

    let dp = Array.from(
        { length: n + 1 },
        () => Array(n + 1).fill(false)
    );

    dp[0][0] = true;

    for (let i = 0; i < n; i++) {
        for (let open = 0; open <= n; open++) {
            if (!dp[i][open]) continue;

            if (s[i] === '(') {
                dp[i + 1][open + 1] = true;
            }

            else if (s[i] === ')') {
                if (open > 0) {
                    dp[i + 1][open - 1] = true;
                }
            }

            else {
                dp[i + 1][open + 1] = true;
                dp[i + 1][open] = true;
                if (open > 0) {
                    dp[i + 1][open - 1] = true;
                }
            }
        }
    }

    return dp[n][0];
};