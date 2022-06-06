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
    int getMaxPath(TreeNode* root, int* maxSum)
    {
        if(!root)
            return 0;
        int lsum = 0, rsum = 0;
        if(root->left)
            lsum = getMaxPath(root->left, maxSum);
        if(root->right)
            rsum = getMaxPath(root->right, maxSum);
        int ans = max(max(root->val, lsum + root->val), rsum+root->val);
        *maxSum = max(max(*maxSum, ans), lsum+rsum+root->val);
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int maxSum = INT_MIN;
        getMaxPath(root, &maxSum);
        return maxSum;
    }
};