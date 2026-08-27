class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};

        for (char c : s)
            cnt[c - 'a']++;

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {

            // We are trying to match target[0..i-1],
            // so check if that prefix is possible.
            for (int j = 0; j < i; j++) {
                cnt[target[j] - 'a']--;

                if (cnt[target[j] - 'a'] < 0) {
                    // Restore what we consumed
                    for (int k = 0; k <= j; k++)
                        cnt[target[k] - 'a']++;

                    goto next;
                }
            }

            // Try to put the smallest character > target[i]
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    string ans = target.substr(0, i);
                    ans += char('a' + c);

                    cnt[c]--;

                    // Fill the remaining positions as small as possible
                    for (int x = 0; x < 26; x++) {
                        ans += string(cnt[x], 'a' + x);
                    }

                    return ans;
                }
            }

            // Restore prefix before trying an earlier position
            for (int j = 0; j < i; j++)
                cnt[target[j] - 'a']++;

            next:;
        }

        return "";
    }
};