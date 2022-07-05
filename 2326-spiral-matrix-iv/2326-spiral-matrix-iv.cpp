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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ans(n, vector<int>(m, -1));
        int i = 0, j = 0;
        while(head)
        {
            while(head && j < m && ans[i][j] == -1)
            {
                ans[i][j] = head->val;
                head = head->next;
                j++;
            }
            j--;
            i++;
            while(head && i < n && ans[i][j] == -1)
            {
                ans[i][j] = head->val;
                head = head->next;
                i++;
            }
            i--;
            j--;
            while(head && j >= 0 && ans[i][j] == -1)
            {
                ans[i][j] = head->val;
                head = head->next;
                j--;
            }
            j++;
            i--;
            while(head && i >= 0 && ans[i][j] == -1)
            {
                ans[i][j] = head->val;
                head = head->next;
                i--;
            }
            i++;
            j++;
            n--;
            m--;
        }
        return ans;
    }
};