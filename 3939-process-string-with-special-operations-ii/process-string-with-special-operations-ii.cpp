class Solution {
public:
    char processStr(string s, long long k) {
        const long long LIM = (long long)1e15;

        int n = s.size();
        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            long long cur = len[i];

            if ('a' <= s[i] && s[i] <= 'z') {
                len[i + 1] = min(LIM, cur + 1);
            } else if (s[i] == '*') {
                len[i + 1] = max(0LL, cur - 1);
            } else if (s[i] == '#') {
                len[i + 1] = min(LIM, cur * 2);
            } else { // '%'
                len[i + 1] = cur;
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (k == len[i]) return ch;
            }
            else if (ch == '#') {
                long long oldLen = len[i];
                if (k >= oldLen) k -= oldLen;
            }
            else if (ch == '%') {
                long long L = len[i];
                k = L - 1 - k;
            }
        }

        return '.';
    }
};