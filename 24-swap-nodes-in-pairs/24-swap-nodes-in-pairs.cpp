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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !(head->next))
            return head;
        ListNode* nxt = head->next;
        // ListNode* fwd = curr->next;
        head->next = swapPairs(nxt->next);
        nxt->next = head;
        return nxt;
        
    }
};