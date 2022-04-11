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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(cnt < left)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        ListNode* leftJoin = prev;
        prev = NULL;
        ListNode* Next = NULL;
        ListNode* rightNode = curr;
        while(cnt <= right)
        {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
            cnt++;
        }
        if(leftJoin)
            leftJoin->next = prev;
        else
            head = prev;
        rightNode->next = curr;
        return head;
        
        
        
    }
};