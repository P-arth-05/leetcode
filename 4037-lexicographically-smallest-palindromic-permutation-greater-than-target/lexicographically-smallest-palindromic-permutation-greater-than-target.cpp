class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = 'a' + i;
            }
        }
        if (odd > 1) return "";

        for (int i = 0; i < 26; ++i) cnt[i] /= 2;

        int n = s.length();
        int half = n / 2;
        string left(half, ' ');

        function<bool(int, bool)> build = [&](int pos, bool greater) -> bool {
            if (pos == half) {
                string lp = left;
                string rp = string(lp.rbegin(), lp.rend());
                string pal = lp + (n % 2 ? string(1, mid) : "") + rp;
                return pal > target;
            }
            char start = greater ? 'a' : target[pos];
            for (char c = start; c <= 'z'; ++c) {
                int idx = c - 'a';
                if (cnt[idx] == 0) continue;
                left[pos] = c;
                cnt[idx]--;
                bool ng = greater || c > target[pos];
                if (build(pos + 1, ng)) return true;
                cnt[idx]++;
            }
            return false;
        };

        if (build(0, false)) {
            string lp = left;
            string rp = string(lp.rbegin(), lp.rend());
            return lp + (n % 2 ? string(1, mid) : "") + rp;
        }
        return "";
    }
};