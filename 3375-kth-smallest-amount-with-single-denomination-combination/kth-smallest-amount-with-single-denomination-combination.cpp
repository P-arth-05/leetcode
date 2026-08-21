class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        auto count = [&](long long x) {
            long long cnt = 0;

            // Inclusion-exclusion over all subsets
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(l, (long long)coins[i]);

                        // Avoid overflow / useless LCM
                        if (l / g > x / coins[i]) {
                            l = x + 1;
                            break;
                        }

                        l = l / g * coins[i];

                        if (l > x)
                            break;
                    }
                }

                if (l > x)
                    continue;

                if (bits % 2 == 1)
                    cnt += x / l;
                else
                    cnt -= x / l;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * k * *min_element(coins.begin(), coins.end());

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};