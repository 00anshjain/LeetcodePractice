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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1 = headA, *curr2 = headB;
        bool flag1 = NULL, flag2 = NULL;
        while(curr1 && curr2 && curr1 != curr2)
        {
            curr1 = curr1->next;
            if(!curr1 && !flag1)
            {
                curr1 = headB;
                flag1 = true;
            }
            curr2 = curr2->next;
            if(!curr2 && !flag2)
            {
                curr2 = headA;
                flag2 = true;
            }
        }
        if(curr1 != curr2)
            return NULL;
        return curr1;
    }
};