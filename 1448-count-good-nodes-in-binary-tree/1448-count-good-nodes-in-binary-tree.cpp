/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int dfs(TreeNode* node, int max){
        if (node == NULL){
            return 0;
        }
        int count =0;
        if (node->val >= max){
            count = 1;
            max = node->val;
        }

        count += dfs(node->left, max);
        count += dfs(node->right, max);

        return count;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);       
    }
};