class Solution {
public:

    pair<int, int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        auto left = solve(root->left);
        auto right = solve(root->right);

        // Rob current node
        int rob = root->val + left.first + right.first;

        // Don't rob current node
        int notRob = max(left.first, left.second)
                   + max(right.first, right.second);

        return {notRob, rob};
    }

    int rob(TreeNode* root) {
        auto ans = solve(root);

        return max(ans.first, ans.second);
    }
};