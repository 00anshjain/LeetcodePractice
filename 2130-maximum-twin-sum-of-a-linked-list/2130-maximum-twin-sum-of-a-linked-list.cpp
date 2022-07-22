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
    int pairSum(ListNode* head) {
        int mx = 0;
        if(!head || !head->next)
            return 0;
        ListNode* slow = head;
        ListNode* fast = head->next;
        vector<int> v;
        v.push_back(slow->val);
        while(fast && fast->next)
        {
            slow  = slow->next;
            fast = fast->next->next;
            v.push_back(slow->val);
        }
        slow = slow->next;
        int n = v.size();
        n--;//for index
        // commented because only even size list here
        
        // if(!fast)
        // {
        //     n--;//this last node doesnt have twin
        // }
        while(slow)
        {
            mx = max(slow->val + v[n], mx);
            n--;
            slow = slow->next;
        }
        return mx;
        
    }
};