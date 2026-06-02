#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
        // Base case: If start index reaches the end, we have a complete permutation
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Try placing each available number at the 'start' position
        for (int i = start; i < nums.size(); ++i) {
            
            // Swap to lock the element at index 'i' into the 'start' position
            std::swap(nums[start], nums[i]);
            
            // Recurse to fill the rest of the array
            backtrack(nums, start + 1, result);
            
            // Backtrack: Undo the swap to restore the array for the next iteration
            std::swap(nums[start], nums[i]);
        }
    }
};