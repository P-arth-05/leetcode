#include <string>
#include <vector>

using namespace std;

class Solution {
    // Structure to hold both the count of valid numbers and the accumulated waviness
    struct Result {
        long long count;
        long long waviness;
    };
    
    // DP Table: [idx][prev1][prev2][isTight][isLeadingZero]
    // Max length of 10^15 is 16 digits, so 20 is a safe size for idx.
    // We use 10 to represent "no digit placed yet" for prev1 and prev2.
    Result dp[20][11][11][2][2];
    
    Result solve(int idx, int p1, int p2, bool tight, bool lz, const string& s) {
        // Base Case: If we've processed all digits, we found 1 valid number configuration.
        // It contributes 0 new waviness from the "void".
        if (idx == s.length()) {
            return {1, 0}; 
        }
        
        // Return memoized result if we've been in this exact state before
        if (dp[idx][p1][p2][tight][lz].count != -1) {
            return dp[idx][p1][p2][tight][lz];
        }
        
        // If tight is true, we can only go up to the digit in our limit string 's'.
        // Otherwise, we can place any digit from 0 to 9.
        int limit = tight ? s[idx] - '0' : 9;
        Result res = {0, 0};
        
        for (int d = 0; d <= limit; d++) {
            bool next_lz = lz && (d == 0);
            
            // Shift our tracked digits for the next state
            int next_p1, next_p2;
            if (next_lz) {
                next_p1 = 10; // Still leading zero, no actual digit placed
                next_p2 = 10;
            } else if (p1 == 10) {
                next_p1 = d;  // This is our very first actual digit
                next_p2 = 10;
            } else {
                next_p1 = d;  // Current digit becomes the new previous digit
                next_p2 = p1; // Old previous digit gets pushed back
            }
            
            bool next_tight = tight && (d == limit);            
            Result sub = solve(idx + 1, next_p1, next_p2, next_tight, next_lz, s);            
            long long current_waviness = 0;
            if (!next_lz && p1 != 10 && p2 != 10) {
                if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) {
                    current_waviness = 1;
                }
            }
            res.count += sub.count;
            res.waviness += sub.waviness + (current_waviness * sub.count);
        }
        return dp[idx][p1][p2][tight][lz] = res;
    }
    long long getWaviness(long long n) {
        if (n < 101) return 0; 
        string s = to_string(n);
        for(int i = 0; i < 20; i++)
            for(int j = 0; j < 11; j++)
                for(int k = 0; k < 11; k++)
                    for(int t = 0; t < 2; t++)
                        for(int l = 0; l < 2; l++)
                            dp[i][j][k][t][l] = {-1, -1};
        return solve(0, 10, 10, true, true, s).waviness;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return getWaviness(num2) - getWaviness(num1 - 1);
    }
};