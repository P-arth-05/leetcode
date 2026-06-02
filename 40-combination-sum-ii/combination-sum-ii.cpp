#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Step 1: Sort the array to easily skip duplicates and enable early stopping
        std::sort(candidates.begin(), candidates.end());
        
        // Step 2: Start backtracking
        backtrack(candidates, target, 0, current, result);
        
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int start, 
                   std::vector<int>& current, std::vector<std::vector<int>>& result) {
        
        // Base case: If target hits 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // PRUNING 1: Skip duplicates at the same depth level of the recursion tree
            // We only do this for i > start so we don't skip valid identical numbers 
            // that are placed at different depths (e.g., [1, 1, 6] for target 8).
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // PRUNING 2: Early stopping
            // Since the array is sorted, if the current element exceeds the target,
            // all subsequent elements will also exceed it.
            if (candidates[i] > target) {
                break;
            }

            // Choose the candidate
            current.push_back(candidates[i]);
            
            // Explore further, reducing the target. 
            // Pass 'i + 1' because we cannot reuse the same element.
            backtrack(candidates, target - candidates[i], i + 1, current, result);
            
            // Backtrack: remove the last choice to explore new branches
            current.pop_back();
        }
    }
};