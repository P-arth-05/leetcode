class Solution {
public:

    TreeNode* build(ListNode* head) {

        if (!head)
            return nullptr;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);

        root->left = build(head);
        root->right = build(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        return build(head);
    }
};