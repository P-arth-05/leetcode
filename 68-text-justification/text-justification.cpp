class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();

        int i = 0;

        while (i < n) {
            int j = i;
            int len = 0;

            while (j < n &&
                   len + words[j].size() + (j - i) <= maxWidth) {
                len += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            if (j == n || gaps == 0) {
                line = words[i];

                for (int k = i + 1; k < j; k++) {
                    line += " ";
                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            } else {
                int spaces = maxWidth - len;
                int base = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j - 1; k++) {
                    line += words[k];

                    line += string(
                        base + (k - i < extra ? 1 : 0),
                        ' '
                    );
                }

                line += words[j - 1];
            }

            res.push_back(line);
            i = j;
        }

        return res;
    }
};