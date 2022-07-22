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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v1;
        vector<int> v2;
        ListNode* curr = head;
        while(curr != NULL)
        {
            if(curr->val <x)
                v2.push_back(curr->val);
            else
                v1.push_back(curr->val);
            curr = curr->next;
        }    
        curr = head;
        for(auto x : v2)
        {
            curr->val = x;
            curr = curr->next;
        }
        for(auto x : v1)
        {
            curr->val = x;
            curr = curr->next;
        }
        return head;
        
    }
};