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
    int steps;
    int recur(TreeNode* root)
    {
        if(!root)
            return 0;
        int l = recur(root->left);
        int r = recur(root->right);
        steps += (abs(l) + abs(r));  
        //even if it has less coin or excess coin, we increase steps as it has to come up by taking step
        // it its gets balanced by l + r then OK otherwise we again send it forwarding by returning l + r
        return l + r + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        steps = 0;
        recur(root);
        return steps;
    }
};