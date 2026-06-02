#include <vector>
#include <algorithm>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // Loop up to the second-to-last element
        for (int i = 0; i < nums.size() - 1; ++i) {
            
            // Update the farthest index we can reach
            farthest = std::max(farthest, i + nums[i]);
            
            // When we finish traversing the current jump window, 
            // we must jump again.
            if (i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }
        
        return jumps;
    }
};