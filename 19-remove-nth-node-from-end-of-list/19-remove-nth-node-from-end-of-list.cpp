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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head;
        if(!head->next && n == 1)
            return NULL;
        // if(n == 1)
        for(int i = 0; i < n-1; i++)
            ahead = ahead->next;
        // cout<<ahead->val;
        ListNode* curr = new ListNode(-1);
        curr->next = head;
        while(ahead->next)
        {
            ahead = ahead->next;
            curr = curr->next;
        }
        // if(curr->next)
        //     curr->next = curr->next->next;
        if(curr->next == head)
            head = head->next;
        else
            curr->next = curr->next->next;
        return head;
        
    }
};