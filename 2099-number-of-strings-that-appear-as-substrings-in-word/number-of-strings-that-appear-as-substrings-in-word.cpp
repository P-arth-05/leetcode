class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for (string &pat : patterns) {

            bool found = false;

            for (int i = 0; i + pat.size() <= word.size(); i++) {

                int j = 0;

                while (j < pat.size() && word[i + j] == pat[j])
                    j++;

                if (j == pat.size()) {
                    found = true;
                    break;
                }
            }

            if (found)
                ans++;
        }

        return ans;
    }
};