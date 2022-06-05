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
    int maxsum=0;
    bool isBST(TreeNode*root,int mini,int maxi)
    {
        if(root==nullptr)
            return true;
        if(root->val<=mini||root->val>=maxi)
            return false;
        return isBST(root->left,mini,root->val) && isBST(root->right,root->val,maxi);
        // return left&&right;
    }
    
    
    int sumBST(TreeNode*root)
    {
        if(!root->left && !root->right)
        {
            if(root->val > 0)
                maxsum = root->val;
            return root->val;
        }
        int lsum = 0, rsum = 0;
        if(root->left)
            lsum = sumBST(root->left);
        if(root->right)
            rsum = sumBST(root->right);
        // cout<<root->val<<"  "<<lsum<<"  "<<rsum<<endl;
        int ans = lsum + rsum + root->val;
        if(maxsum < ans)
            maxsum = ans;
        return (lsum + rsum + root->val);
    }
    int maxSumBST(TreeNode* root) {
        if(root==nullptr)
            return 0;
        if(isBST(root,INT_MIN,INT_MAX))
        {
            // cout<<"Yes"<<endl;
            int k = sumBST(root);
            if(k < 0)
                return 0;
            return maxsum;
        }
        // return 0;
        return max(maxSumBST(root->left),maxSumBST(root->right));
    }
};