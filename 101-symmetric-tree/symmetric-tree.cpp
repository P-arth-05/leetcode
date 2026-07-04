class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});

        while (!q.empty()) {
            auto [left, right] = q.front();
            q.pop();

            if (!left && !right)
                continue;

            if (!left || !right)
                return false;

            if (left->val != right->val)
                return false;

            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }

        return true;
    }
};