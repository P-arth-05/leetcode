/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* head;

    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int ans = head->val;
        ListNode* curr = head;
        int cnt = 1;

        while (curr) {
            if (rand() % cnt == 0)
                ans = curr->val;

            curr = curr->next;
            cnt++;
        }

        return ans;
    }
};