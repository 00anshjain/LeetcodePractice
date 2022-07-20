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
    int getCnt(TreeNode* root, int mx)
    {
        if(!root)
            return 0;
        mx = max(mx, root->val);
        return getCnt(root->left, mx) + getCnt(root->right, mx) + (root->val >= mx);
    }
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        return getCnt(root, mx);
        
    }
};