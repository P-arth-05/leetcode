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

void postorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;

    // Left
    postorder(root->left, result, index);

    // Right
    postorder(root->right, result, index);

    // Root
    result[(*index)++] = root->val;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = malloc(10000 * sizeof(int));
    *returnSize = 0;

    postorder(root, result, returnSize);

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

