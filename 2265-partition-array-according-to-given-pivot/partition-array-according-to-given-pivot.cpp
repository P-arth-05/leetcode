class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result;
        result.reserve(nums.size()); 
        for (int num : nums) {
            if (num < pivot) {
                result.push_back(num);
            }
        }
        for (int num : nums) {
            if (num == pivot) {
                result.push_back(num);
            }
        }
        for (int num : nums) {
            if (num > pivot) {
                result.push_back(num);
            }
        }
        return result;
    }
};