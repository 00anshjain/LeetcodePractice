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
    TreeNode* recur(vector<int> &pre, int l, int r)
    {
        if(l > r)
            return NULL;
        TreeNode* root = new TreeNode(pre[l]);
        l++;
        int le = l;
        while(l <= r && pre[l] < root->val)
            l++;
        root->left = recur(pre, le, l-1);
        root->right = recur(pre, l, r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return recur(pre, 0, pre.size() - 1);
    }
};