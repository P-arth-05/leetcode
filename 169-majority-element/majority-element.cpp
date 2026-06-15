class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0]; 
        int count = 1; 
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i+1]) {
                count++;
            } else {
                if (count > n/2) {
                    ans = nums[i];
                }
                count = 1; 
            }
        }
        if (count > n/2) {
            ans = nums[n-1];
        }
        return ans;
    }
};