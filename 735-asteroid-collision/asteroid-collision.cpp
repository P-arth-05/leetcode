class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a : asteroids) {
            while (!st.empty() && st.top() > 0 && a < 0 && st.top() < -a) {
                st.pop();
            }
            if (st.empty() || a > 0 || st.top() < 0) {
                st.push(a);
            }
            else if (st.top() == -a) {
                st.pop();
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};