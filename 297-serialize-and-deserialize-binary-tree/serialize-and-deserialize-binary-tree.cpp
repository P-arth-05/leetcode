/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode* root, string &s) {
        if (!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        int idx = 0;
        return build(nodes, idx);
    }

    TreeNode* build(vector<string>& nodes, int &idx) {
        if (nodes[idx] == "#") {
            idx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[idx++]));

        root->left = build(nodes, idx);
        root->right = build(nodes, idx);

        return root;
    }
};