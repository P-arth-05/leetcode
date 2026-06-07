class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m > n) return -1;
        if (m == n) {
            if (haystack == needle) return 0;
            else return -1;
        } 
        int indn = 0;
        for(int i = 0; i < n; i++) {
            if (haystack[i] == needle[indn]) {
                indn++;
            } else {
                i = i - indn;
                indn = 0;
            }
            if (indn == m) return i - m + 1; 
        }
        return -1;
    }
};