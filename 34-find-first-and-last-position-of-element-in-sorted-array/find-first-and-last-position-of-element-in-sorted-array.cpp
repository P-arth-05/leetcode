#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        if (nums.empty()) return ans;
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1; 
            } else {
                l = mid + 1;
            }
        }
        if (l < nums.size() && nums[l] == target) {
            ans[0] = l;
        } else {
            return ans; 
        }
        l = 0; 
        r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
        ans[1] = r;
        return ans;
    }
};