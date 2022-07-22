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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while(head)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        int n = ans.size();
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= ans[i])
            {
                st.pop();
            }
            int k = ans[i];
            if(st.empty())
                ans[i] = 0;
            else
                ans[i] = st.top();
            st.push(k);
        }
        return ans;
    }
};