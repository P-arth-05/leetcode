class Solution {
public:
    int lower, upper;

    int mergeSort(vector<long long>& pre, int l, int r) {

        if (r - l <= 1)
            return 0;

        int mid = (l + r) / 2;

        int cnt =
            mergeSort(pre, l, mid)
          + mergeSort(pre, mid, r);

        int low = mid;
        int high = mid;

        for (int i = l; i < mid; i++) {

            while (low < r &&
                   pre[low] - pre[i] < lower)
                low++;

            while (high < r &&
                   pre[high] - pre[i] <= upper)
                high++;

            cnt += high - low;
        }

        inplace_merge(pre.begin() + l,
                      pre.begin() + mid,
                      pre.begin() + r);

        return cnt;
    }

    int countRangeSum(vector<int>& nums,
                      int lower,
                      int upper) {

        this->lower = lower;
        this->upper = upper;

        vector<long long> pre(nums.size() + 1);

        for (int i = 0; i < nums.size(); i++)
            pre[i + 1] = pre[i] + nums[i];

        return mergeSort(pre, 0, pre.size());
    }
};