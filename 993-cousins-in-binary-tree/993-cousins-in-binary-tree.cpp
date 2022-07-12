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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            int cnt = 0;
            while(n--)
            {
                auto t = q.front();
                q.pop();
                // if(t->left && t-> right && ((t->left->val == x) || (t->left->val == y)) && t->right->val == (x+y-(t->left->val)))
                //     return false;
                if(t->left)
                {
                    if(t->left->val == x || t->left->val == y)
                    {
                        cnt++;
                        if(t->right && (t->right->val ==x || t->right->val == y))
                            return false;
                    } 
                    if(cnt == 0)
                        q.push(t->left);
                }
                if(t->right)
                {
                    if(t->right->val == x || t->right->val == y)
                    {
                        cnt++;
                    } 
                    if(cnt == 0)
                        q.push(t->right);
                }
                if(cnt == 2)
                    return true;
            }
            if(cnt > 0)
                return false;
        }
        return false;
        
    }
};