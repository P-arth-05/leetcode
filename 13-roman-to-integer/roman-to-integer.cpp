class Solution {
public:
    int romanToInt(string s) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int ans = 0;
        for (int i = 0; i < 13; i++) {
            while (s.find(symbols[i]) == 0) {
                ans += values[i];
                s.erase(0, symbols[i].length());
            }
        }
        return ans;
    }
};