class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* smallTail = smallDummy;
        ListNode* largeTail = largeDummy;

        while (head) {

            if (head->val < x) {
                smallTail->next = head;
                smallTail = smallTail->next;
            }
            else {
                largeTail->next = head;
                largeTail = largeTail->next;
            }

            head = head->next;
        }

        largeTail->next = nullptr;
        smallTail->next = largeDummy->next;

        return smallDummy->next;
    }
};