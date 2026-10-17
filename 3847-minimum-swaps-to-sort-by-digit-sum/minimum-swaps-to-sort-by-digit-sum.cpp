
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        auto digitSum = [](int x) {
            int s = 0;
            while (x > 0) {
                s += x % 10;
                x /= 10;
            }
            return s;
        };

        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end(), [&](auto x, auto y) {
            int sx = digitSum(x.first);
            int sy = digitSum(y.first);

            if (sx != sy) return sx < sy;
            return x.first < y.first;
        });

        vector<int> p(n);

        for (int i = 0; i < n; i++)
            p[a[i].second] = i;

        int ans = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i] || p[i] == i) continue;

            int j = i, len = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = p[j];
                len++;
            }

            ans += len - 1;
        }

        return ans;
    }
};
