class Solution {
public:
    int modPow(int a, int b) {
        int ans = 1;

        while (b > 0) {
            if (b & 1)
                ans = (ans * a) % 1337;

            a = (a * a) % 1337;
            b /= 2;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        a %= 1337;

        int ans = 1;

        for (int digit : b) {
            ans = modPow(ans, 10) * modPow(a, digit) % 1337;
        }

        return ans;
    }
};