class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int idx, int leftRem, int rightRem,
             int balance, string &curr) {

        if (idx == s.size()) {
            if (leftRem == 0 && rightRem == 0 && balance == 0)
                ans.insert(curr);
            return;
        }

        char c = s[idx];

        if (c == '(') {

            // Remove '('
            if (leftRem > 0)
                dfs(s, idx + 1, leftRem - 1, rightRem, balance, curr);

            // Keep '('
            curr.push_back(c);
            dfs(s, idx + 1, leftRem, rightRem, balance + 1, curr);
            curr.pop_back();
        }
        else if (c == ')') {

            // Remove ')'
            if (rightRem > 0)
                dfs(s, idx + 1, leftRem, rightRem - 1, balance, curr);

            // Keep ')' only if there is a matching '('
            if (balance > 0) {
                curr.push_back(c);
                dfs(s, idx + 1, leftRem, rightRem, balance - 1, curr);
                curr.pop_back();
            }
        }
        else {
            // Always keep letters
            curr.push_back(c);
            dfs(s, idx + 1, leftRem, rightRem, balance, curr);
            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0, rightRem = 0;

        // Count minimum removals needed
        for (char c : s) {
            if (c == '(') {
                leftRem++;
            } else if (c == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string curr;
        dfs(s, 0, leftRem, rightRem, 0, curr);

        return vector<string>(ans.begin(), ans.end());
    }
};