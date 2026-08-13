class Solution {
public:
    struct Node {
        char lc, rc;
        int len;
        int pref, suff, best;

        Node() {
            lc = rc = '#';
            len = pref = suff = best = 0;
        }

        Node(char c) {
            lc = rc = c;
            len = pref = suff = best = 1;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.pref = a.pref;
        if (a.pref == a.len && a.rc == b.lc)
            res.pref = a.len + b.pref;

        res.suff = b.suff;
        if (b.suff == b.len && a.rc == b.lc)
            res.suff = b.len + a.suff;

        res.best = max(a.best, b.best);

        if (a.rc == b.lc)
            res.best = max(res.best, a.suff + b.pref);

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(s, 2 * node, l, mid);
        build(s, 2 * node + 1, mid + 1, r);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * node, l, mid, pos, c);
        else
            update(2 * node + 1, mid + 1, r, pos, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        seg.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, pos, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};