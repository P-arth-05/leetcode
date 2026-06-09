class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long globalMin = INT_MAX;
        long long globalMax = INT_MIN;
        for (int num : nums) {
            if (num < globalMin) globalMin = num;
            if (num > globalMax) globalMax = num;
        }
        long long bestSubarrayValue = globalMax - globalMin;
        return bestSubarrayValue * k;
    }
};