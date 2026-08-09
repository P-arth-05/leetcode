class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1,
                                       vector<int>& nums2,
                                       int k) {

        vector<vector<int>> ans;

        // {sum, index in nums1, index in nums2}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        int n = min((int)nums1.size(), k);

        // Start with the first element of nums2
        for (int i = 0; i < n; i++) {
            pq.push({
                nums1[i] + nums2[0],
                i,
                0
            });
        }

        while (k-- && !pq.empty()) {

            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // Move to the next element in nums2
            if (j + 1 < nums2.size()) {
                pq.push({
                    nums1[i] + nums2[j + 1],
                    i,
                    j + 1
                });
            }
        }

        return ans;
    }
};