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
    int recur(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        int l = recur(root->left, ans);
        int r = recur(root->right, ans);
        ans = max(max(max(max(ans, l + r + root->val), l + root->val), r + root->val), root->val);
        return max(max(l + root->val, r + root->val), root->val);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int a = recur(root, ans);
        return max(ans, a);
    }
};