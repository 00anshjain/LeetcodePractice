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
    int ans;
    int DFS(TreeNode* root, int v)
    {
        if(!root)
            return 0;
        int l = DFS(root->left, root->val);
        int r = DFS(root->right, root->val);
        // ans = max(ans, l + r);
        ans = max(ans, l+r);
        if(root->val == v)
            return max(l, r) + 1;
        return 0;
        
    }
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        DFS(root, 10003);
        return ans;
    }
};