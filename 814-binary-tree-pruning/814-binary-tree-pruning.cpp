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
    bool hasOne(TreeNode* root)
    {
        if(!root)
            return false;
        bool l = hasOne(root->left);
        if(!l)
            root->left = NULL;
        bool r = hasOne(root->right);
        if(!r)
            root->right = NULL;
        if(l || r || root->val == 1)
            return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!hasOne(root))
            return NULL;
        return root;
        
    }
};