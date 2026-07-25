class TrieNode {
public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        memset(child, 0, sizeof(child));
        word = "";
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string &word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i, int j,
             TrieNode* node) {

        char ch = board[i][j];

        if (ch == '#' || !node->child[ch - 'a'])
            return;

        node = node->child[ch - 'a'];

        if (!node->word.empty()) {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];

            if (nr >= 0 && nr < board.size() &&
                nc >= 0 && nc < board[0].size())
                dfs(board, nr, nc, node);
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string &w : words)
            insert(w);

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                dfs(board, i, j, root);

        return ans;
    }
};