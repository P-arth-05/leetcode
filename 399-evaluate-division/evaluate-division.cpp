class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(string src, string dst, unordered_set<string>& vis) {

        if (src == dst)
            return 1.0;

        vis.insert(src);

        for (auto &[next, wt] : graph[src]) {

            if (vis.count(next))
                continue;

            double val = dfs(next, dst, vis);

            if (val != -1.0)
                return wt * val;
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {

        for (int i = 0; i < equations.size(); i++) {

            string a = equations[i][0];
            string b = equations[i][1];

            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }

        vector<double> ans;

        for (auto &q : queries) {

            string src = q[0];
            string dst = q[1];

            if (!graph.count(src) || !graph.count(dst)) {
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> vis;

            ans.push_back(dfs(src, dst, vis));
        }

        return ans;
    }
};