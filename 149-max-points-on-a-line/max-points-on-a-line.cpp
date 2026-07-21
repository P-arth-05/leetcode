class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> cnt;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize sign
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }

                ans = max(ans, ++cnt[{dy, dx}] + 1);
            }
        }

        return ans;
    }
};