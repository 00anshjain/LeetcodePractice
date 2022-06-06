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
    void sumNum(TreeNode* root, int *totalSum, int sum)
    {
        if(!root)
            return;
        sum += root->val;
        if(!root->left && !root->right)
        {
            *totalSum += sum;
            return;
        }
        if(root->left)
            sumNum(root->left, totalSum, sum*10);
        if(root->right)
            sumNum(root->right, totalSum, sum*10);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int totalSum = 0;
        sumNum(root, &totalSum, 0);
        return totalSum;
    }
};