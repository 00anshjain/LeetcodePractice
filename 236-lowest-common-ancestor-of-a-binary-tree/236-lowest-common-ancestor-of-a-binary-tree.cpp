/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        if(!root)
            return NULL;
        if(root == n1 || root == n2)
            return root;
        TreeNode* k1 = lowestCommonAncestor(root->left, n1, n2);
        TreeNode* k2 = lowestCommonAncestor(root->right, n1, n2);
        if(k1 && k2)
            return root;
        if(k1)
            return k1;
        return k2;
    }
};