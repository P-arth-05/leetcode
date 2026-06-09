class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> mpp;
        for(auto const &str : strs)
        {
            string s = str;
            sort(s.begin(),s.end());
            mpp[s].push_back(str); 
        }
        vector<vector<string>> ans;
        for(auto const &str : mpp)
        {
            ans.push_back(str.second);
        }
        return ans;
    }
};