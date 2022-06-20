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
    //largest independent set problem
    // pair for if root taken then maxm value, if root not taken then maxm value
    pair<int, int> LIS(TreeNode* root) 
    {
        if(!root)
            return {0, 0};
        auto l = LIS(root->left);
        auto r = LIS(root->right);
        return {l.second + r.second + root->val, max(l.first, l.second) + max(r.second, r.first)};
    }
    int rob(TreeNode* root) {
        auto p = LIS(root);
        return max(p.first, p.second);
    }
};