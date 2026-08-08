class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[j] = latest index in word1 that can be used
        // to match word2[j] while matching word2[j..] exactly.
        vector<int> suf(m, -1);

        int p = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0 && word1[p] != word2[j])
                p--;

            if (p < 0)
                break;

            suf[j] = p--;
        }

        vector<int> ans;
        int p1 = 0;
        bool mismatch = false;

        for (int j = 0; j < m; j++) {
            while (p1 < n) {

                if (word1[p1] == word2[j]) {
                    ans.push_back(p1++);
                    break;
                }

                // Use mismatch here only if suffix can
                // be matched exactly after this index.
                if (!mismatch &&
                    (j == m - 1 || suf[j + 1] > p1)) {

                    ans.push_back(p1++);
                    mismatch = true;
                    break;
                }

                p1++;
            }

            if (ans.size() != j + 1)
                return {};
        }

        return ans;
    }
};