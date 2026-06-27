class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special case for 1
        if (freq.count(1)) {
            ans = (freq[1] % 2 == 0) ? freq[1] - 1 : freq[1];
        }

        for (auto &[start, _] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!freq.count(cur))
                    break;

                if (freq[cur] == 1) {
                    len++;
                    break;
                }

                if (freq[cur] >= 2) {
                    len += 2;

                    // Prevent overflow before squaring
                    if (cur > 1000000000LL)
                        break;

                    long long nxt = cur * cur;

                    if (!freq.count(nxt)) {
                        // Can't continue, remove one element from the last pair
                        len--;
                        break;
                    }

                    cur = nxt;
                }
            }

            ans = max(ans, len);
        }

        return ans;
    }
};