class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0;
        for (int x : nums)
            xr ^= x;

        uint32_t diff = (uint32_t)xr & -(uint32_t)xr;

        int a = 0, b = 0;
        for (int x : nums) {
            if ((uint32_t)x & diff)
                a ^= x;
            else
                b ^= x;
        }

        return {a, b};
    }
};