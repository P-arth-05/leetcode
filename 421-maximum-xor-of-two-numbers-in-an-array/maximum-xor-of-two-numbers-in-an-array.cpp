class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->child[bit])
                node->child[bit] = new TrieNode();

            node = node->child[bit];
        }
    }

    int findMaxXor(int num) {
        TrieNode* node = root;

        int ans = 0;

        for (int i = 31; i >= 0; i--) {

            int bit = (num >> i) & 1;

            if (node->child[1 - bit]) {

                ans |= (1 << i);
                node = node->child[1 - bit];
            }
            else {

                node = node->child[bit];
            }
        }

        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {

        for (int x : nums)
            insert(x);

        int ans = 0;

        for (int x : nums)
            ans = max(ans, findMaxXor(x));

        return ans;
    }
};