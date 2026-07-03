class Solution {
public:
    TreeNode* prev = nullptr;

    bool inorder(TreeNode* root) {

        if (!root)
            return true;

        if (!inorder(root->left))
            return false;

        if (prev && prev->val >= root->val)
            return false;

        prev = root;

        return inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }
};