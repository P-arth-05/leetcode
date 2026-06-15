/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        if (head == NULL || head->next == NULL) return NULL;
        ListNode* temp = head;
        while (temp != NULL){
            temp = temp->next;
            n++;
        }
        ListNode* mid = head;
        for (int i = 1; i < n/2; i++){
            mid = mid->next;
        }
        mid->next = mid->next->next;
        return head;
    }
};