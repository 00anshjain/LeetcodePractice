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
    bool inorder(TreeNode* root, TreeNode* n1, TreeNode* n2)
    {
        if(!root)
            return false;
        if(root == n1 || root == n2)
            return true;
        if(inorder(root->right, n1, n2) || inorder(root->left, n1, n2))
            return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        // if(!root)
        //     return NULL;
        if(root == n1 || root == n2)
            return root;
        bool k1 = inorder(root->left, n1, n2);
        bool k2 = inorder(root->right, n1, n2);
        if(k1 && k2)
            return root;
        if(k1)
            return lowestCommonAncestor(root->left, n1, n2);
        return lowestCommonAncestor(root->right, n1, n2);
    }
};