class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int check[n+1];
        for (int i=0; i<n+1; i++){
            check[i]=i+1;
        }
        for (int i=0; i<n; i++){
            if (nums[i]>0 && nums[i]<=n+1){
                check[nums[i]-1] = 0;
            }
        }
        for (int i=0; i<n+1; i++){
            if (check[i]>0){
                return check[i];
                break;
            }
        }
        return 0;
    }
};