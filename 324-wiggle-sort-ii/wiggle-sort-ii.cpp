class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int median = *midPtr;

        auto idx = [&](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        int left = 0, i = 0, right = n - 1;

        while (i <= right) {
            if (nums[idx(i)] > median) {
                swap(nums[idx(left)], nums[idx(i)]);
                left++;
                i++;
            }
            else if (nums[idx(i)] < median) {
                swap(nums[idx(i)], nums[idx(right)]);
                right--;
            }
            else {
                i++;
            }
        }
    }
};