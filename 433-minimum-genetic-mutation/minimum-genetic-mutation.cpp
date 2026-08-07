class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        unordered_set<string> valid(bank.begin(), bank.end());

        if (!valid.count(endGene))
            return -1;

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({startGene, 0});
        vis.insert(startGene);

        string genes = "ACGT";

        while (!q.empty()) {

            auto [curr, steps] = q.front();
            q.pop();

            if (curr == endGene)
                return steps;

            for (int i = 0; i < 8; i++) {

                char old = curr[i];

                for (char ch : genes) {

                    curr[i] = ch;

                    if (valid.count(curr) &&
                        !vis.count(curr)) {

                        vis.insert(curr);
                        q.push({curr, steps + 1});
                    }
                }

                curr[i] = old;
            }
        }

        return -1;
    }
}
;