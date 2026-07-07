class Solution {
public:
    long long sumAndMultiply(int n) {
        long long rev = 0;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit == 0) continue;

            sum += digit;
            rev = rev * 10 + digit;
        }

        long long num = 0;
        while (rev > 0) {
            num = num * 10 + rev % 10;
            rev /= 10;
        }

        return num * 1LL * sum;
    }
};