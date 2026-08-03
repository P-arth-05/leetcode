class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int x : nums) {
            while (!st.empty() && drop && st.back() < x) {
                st.pop_back();
                drop--;
            }
            st.push_back(x);
        }

        st.resize(k);
        return st;
    }

    bool greaterVec(vector<int>& a, int i,
                    vector<int>& b, int j) {

        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size())
            return true;

        if (i == a.size())
            return false;

        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {

        vector<int> ans;

        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {

            if (greaterVec(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }

        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1,
                          vector<int>& nums2,
                          int k) {

        vector<int> ans;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = max(0, k - m);
             i <= min(k, n);
             i++) {

            auto a = maxSubsequence(nums1, i);
            auto b = maxSubsequence(nums2, k - i);

            auto cur = merge(a, b);

            if (greaterVec(cur, 0, ans, 0))
                ans = cur;
        }

        return ans;
    }
};