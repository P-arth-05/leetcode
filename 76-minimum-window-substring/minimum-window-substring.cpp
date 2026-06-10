class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        vector<int> map(128, 0);
        for (char c : t) {
            map[c]++;
        }
        int l = 0;
        int r = 0;
        int len = t.length();
        int minlen = INT_MAX;
        int start = 0;
        while (r<s.length()){
            if (map[s[r]] > 0) {
                len--;
            }
            map[s[r]]--;
            r++;
            while(len == 0){
                if (r-l<minlen){ minlen = r - l; start = l; }
                map[s[l]]++;
                if (map[s[l]] > 0) {
                    len++;
                }
                l++;
            }
        }
        if (minlen == INT_MAX) return "";
        return s.substr(start, minlen);
    }
};