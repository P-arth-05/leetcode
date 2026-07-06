class Solution {
public:
    void update(vector<int>& btree, int i, int val){
        for(;i < btree.size(); i+=i&(-i))
            btree[i]+=val;
    }
    int query(vector<int>& btree, int i){
        int sum=0;
        for(; i>0; i-=i&(-i)){
            sum+=btree[i];
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> btree(20001, 0);
        vector<int> out(n, 0);
        for(int i=n-1; i>=0; i--){
            out[i] = query(btree, nums[i] + 10000);
            update(btree, nums[i] + 10001, 1);
        }
        return out;
    }
};