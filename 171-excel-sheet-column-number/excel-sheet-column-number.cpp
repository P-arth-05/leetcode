class Solution {
public:
    int titleToNumber(string c) {
        int ans = 0, n = c.size();
        for(int i=0;i<n;i++){
            ans += (c[i]-'A'+1)*(pow(26,n-1-i));
        }
        return ans;
    }
};