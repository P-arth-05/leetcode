class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int,int>> events;

        for (auto &b : buildings) {
            events.push_back({b[0], -b[2]});
            events.push_back({b[1],  b[2]});
        }

        sort(events.begin(), events.end());

        multiset<int> heights;
        heights.insert(0);

        int prev = 0;

        vector<vector<int>> ans;

        for (auto &[x, h] : events) {

            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));

            int curr = *heights.rbegin();

            if (curr != prev) {
                ans.push_back({x, curr});
                prev = curr;
            }
        }

        return ans;
    }
};