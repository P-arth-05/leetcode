class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        unordered_set<int> values(nums.begin(), nums.end());

        unordered_set<int> pairXor;
        for (int x : values) {
            for (int y : values) {
                pairXor.insert(x ^ y);
            }
        }

        vector<bool> seen(2048, false);

        for (int xy : pairXor) {
            for (int z : values) {
                seen[xy ^ z] = true;
            }
        }

        int ans = 0;
        for (bool x : seen)
            ans += x;

        return ans;
    }
};