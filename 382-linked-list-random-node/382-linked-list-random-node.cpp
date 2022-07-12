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
    ListNode* root;  
    int sz = 0;
    Solution(ListNode* head) {
        root = head;
        sz = 0;
        while(head)
        {
            sz++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int r = rand()%sz;
        ListNode* curr = root;
        while(r-- > 0)
        {
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */