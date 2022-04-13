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
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return NULL;
        int cnt = 0;
        ListNode* curr = head;
        ListNode* ahead = NULL;
        ListNode* prev = NULL;
        ListNode* check = head;
        while(cnt++ < k)
        {
            if(!check)
                return head;
            check = check->next;
        }
        cnt = 0;
        while(cnt++ < k)
        {
            ahead = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = ahead;
        }
        if(ahead)
            head->next = reverseKGroup(ahead, k);
        return prev;
        
        
        
        
        
    }
};