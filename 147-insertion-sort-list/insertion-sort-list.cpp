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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> vals;

    ListNode* cur = head;
    while (cur) {
        vals.push_back(cur->val);
        cur = cur->next;
    }

    sort(vals.begin(), vals.end());

    cur = head;
    int i = 0;
    while (cur) {
        cur->val = vals[i++];
        cur = cur->next;
    }

    return head;
    }
};