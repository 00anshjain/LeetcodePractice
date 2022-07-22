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
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(left > 1)
        {
            prev = curr;
            curr = curr->next;
            right--;
            left--;
        }
        // Node* prev = 
        ListNode* leftJoin = prev;
        ListNode* rightJoin = curr;
        while(left <= right)
        {
            ListNode* ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
            left++;
        }
        if(leftJoin)
            leftJoin->next = prev;
        else
            head = prev;
        rightJoin->next = curr;
        return head;
    }
};