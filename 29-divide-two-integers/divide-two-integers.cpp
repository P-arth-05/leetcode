#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        long long dvd = std::abs((long long)dividend);
        long long dvs = std::abs((long long)divisor);
        long long quotient = 0;
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;       // temp = temp * 2
                multiple <<= 1;   // multiple = multiple * 2
            }
            dvd -= temp;
            quotient += multiple;
        }
        
        return isNegative ? -quotient : quotient;
    }
};