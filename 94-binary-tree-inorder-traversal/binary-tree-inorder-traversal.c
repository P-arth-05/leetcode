/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    // Left
    inorder(root->left, result, index);

    // Root
    result[(*index)++] = root->val;

    // Right
    inorder(root->right, result, index);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(10000 * sizeof(int));
    *returnSize = 0;

    inorder(root, result, returnSize);

    return result;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

