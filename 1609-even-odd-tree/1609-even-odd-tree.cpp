/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool oddLevel = true;
        while(!q.empty())
        {
            oddLevel = !oddLevel;
            int n = q.size();
            int k;
            if(oddLevel)
                k = INT_MAX;
            else
                k = INT_MIN;
            while(n--)
            {
                
                TreeNode* curr = q.front();
                q.pop();
                if(oddLevel)
                {
                    if(curr->val %2 == 1)
                        return false;
                    if(curr->val >= k)
                        return false;
                    k = curr->val;
                }
                if(!oddLevel)
                {
                    if(curr->val %2 == 0)
                        return false;
                    if(curr->val <= k)
                        return false;
                    k = curr->val;
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return true;
    }
};