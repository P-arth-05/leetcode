class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 
        int n = strs.size();
        int minLen = strs[0].size(); 
        for(int i = 1; i < n; i++){
            minLen = min(minLen, (int)strs[i].size());
        }
        
        string ans = "";
        for(int i = 0; i < minLen; i++){
            char current_char = strs[0][i]; 
            for(int j = 1; j < n; j++){
                if (strs[j][i] != current_char){
                    return ans;
                }
            }
            ans += current_char; 
        }
        return ans;
    }
};