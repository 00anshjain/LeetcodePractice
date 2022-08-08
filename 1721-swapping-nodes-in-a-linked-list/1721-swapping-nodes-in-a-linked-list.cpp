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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* x = head, *x_prev = NULL;
        for(int i = 1; i < k; i++)
        {
            x_prev = x;
            x = x->next;
        }
        ListNode* t = head;
        int n = 0;
        while(t)
        {
            n++;
            t = t->next;
        }
        ListNode* y = head, *y_prev = NULL;
        for(int i = 1; i < n-k+1; i++)
        {
            y_prev = y;
            y = y->next;
        }
        if(y_prev)
            y_prev->next = x;
        if(x_prev)
            x_prev->next = y;
        ListNode* temp = x->next;
        x->next = y->next;
        y->next = temp;
        if(x->next == NULL)//basically x was first node now last node
            head = y;
        if(y->next == NULL)
            head = x;
        return head;
        
    }
};