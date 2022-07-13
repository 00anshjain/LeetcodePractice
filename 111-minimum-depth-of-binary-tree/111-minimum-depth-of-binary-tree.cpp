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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int ans1 = INT_MAX, ans2 = INT_MAX;
        if(root->left)
        {
            ans1 = minDepth(root->left);
        }
        if(root->right)
        {
            ans2 = minDepth(root->right);
        }
        int a = min(ans1, ans2);
        return a+1;
        
                

    }
};