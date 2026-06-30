class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int index, int parts, string curr) {

        // Formed 4 parts
        if (parts == 4) {
            if (index == s.size()) {
                curr.pop_back();          // remove last '.'
                ans.push_back(curr);
            }
            return;
        }

        for (int len = 1; len <= 3; len++) {

            if (index + len > s.size())
                break;

            string part = s.substr(index, len);

            // Leading zero not allowed
            if (part.size() > 1 && part[0] == '0')
                continue;

            int num = stoi(part);

            if (num > 255)
                continue;

            backtrack(s, index + len, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, 0, "");
        return ans;
    }
};