class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n,0), rightsum(n,0), ans(n,0);
        for(int i=0;i<n;i++){
            if (i == 0) continue;
            leftsum[i]= nums[i-1] + leftsum[i-1];
        }
        for(int i=n-1;i>=0;i--){
            if (i == n-1) continue;
            rightsum[i]= nums[i+1] + rightsum[i+1];
        }
        for(int i =0;i<n;i++){
            ans[i]=abs(rightsum[i]-leftsum[i]);
        }
        return ans;
    }
};