class Trie {
    struct TrieNode {
        TrieNode* child[26];
        bool isEnd;

        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->child[idx])
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!curr->child[idx])
                return false;

            curr = curr->child[idx];
        }

        return curr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (!curr->child[idx])
                return false;

            curr = curr->child[idx];
        }

        return true;
    }
};