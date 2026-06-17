#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        // Base case: if the tree is empty, return an empty vector
        if (root == nullptr) {
            return result;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* current = st.top();
            st.pop();
            result.push_back(current->val);
            if (current->right != nullptr) {
                st.push(current->right);
            }
            if (current->left != nullptr) {
                st.push(current->left);
            }
        }
        
        return result;
    }
};