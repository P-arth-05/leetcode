class Solution {
public:
    long getBucket(long x, long w) {
        return x >= 0 ? x / w : ((x + 1) / w) - 1;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {
        if (valueDiff < 0)
            return false;

        unordered_map<long, long> bucket;
        long width = (long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {
            long num = nums[i];
            long id = getBucket(num, width);

            if (bucket.count(id))
                return true;

            if (bucket.count(id - 1) &&
                abs(num - bucket[id - 1]) <= valueDiff)
                return true;

            if (bucket.count(id + 1) &&
                abs(num - bucket[id + 1]) <= valueDiff)
                return true;

            bucket[id] = num;

            if (i >= indexDiff) {
                long oldId = getBucket(nums[i - indexDiff], width);
                bucket.erase(oldId);
            }
        }

        return false;
    }
};