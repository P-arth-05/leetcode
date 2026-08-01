class Solution {
public:
    vector<string> ans;

    void dfs(string &num, long long target,
             int idx, long long curr,
             long long prev,
             string path) {

        if (idx == num.size()) {
            if (curr == target)
                ans.push_back(path);
            return;
        }

        long long val = 0;

        for (int i = idx; i < num.size(); i++) {

            if (i > idx && num[idx] == '0')
                break;

            val = val * 10 + (num[i] - '0');

            string s = num.substr(idx, i - idx + 1);

            if (idx == 0) {
                dfs(num, target,
                    i + 1,
                    val,
                    val,
                    s);
            }
            else {

                dfs(num, target,
                    i + 1,
                    curr + val,
                    val,
                    path + "+" + s);

                dfs(num, target,
                    i + 1,
                    curr - val,
                    -val,
                    path + "-" + s);

                dfs(num, target,
                    i + 1,
                    curr - prev + prev * val,
                    prev * val,
                    path + "*" + s);
            }
        }
    }

    vector<string> addOperators(string num, int target) {

        dfs(num, target, 0, 0, 0, "");

        return ans;
    }
};