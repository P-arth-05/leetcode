class Solution {
    vector<int>& nums;

public:
    Solution(vector<int>& nums) : nums(nums) {
        srand(time(0));
    }

    int pick(int target) {
        int ans = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                count++;

                // Pick current index with probability 1/count
                if (rand() % count == 0)
                    ans = i;
            }
        }

        return ans;
    }
};