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

//copied from discussion just to check time
class Solution {
public:
    
    int ans=0;
    
    bool vbst(TreeNode *t,int l,int r)
    {
        if(!t)return 1;
        
        if(t->val<=l or t->val>=r)return 0;
    
        return vbst(t->left,l,t->val) and vbst(t->right,t->val,r);
    }
    
    int maxSum(TreeNode* t,int &ma)
    {
        if(!t)return 0;
        
        int l=maxSum(t->left,ma);
        int r=maxSum(t->right,ma);
        int v=l+r+t->val;
        ma=max(ma,v);
        
        return v;
    }
    
    void solve(TreeNode* t)
    {
        if(!t)return;
        int sum=0;
        
        if(vbst(t,INT_MIN,INT_MAX))
        {   
            maxSum(t,sum);
            ans=max(ans,sum);
            return ;
        }
        
        solve(t->left),solve(t->right);
    }
    
    int maxSumBST(TreeNode* root) {
        
        if(!root)return 0;
        
        solve(root);
        return ans;
    }
};