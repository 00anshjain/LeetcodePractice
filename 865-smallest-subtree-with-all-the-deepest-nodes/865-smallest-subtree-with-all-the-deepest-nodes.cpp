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
    // TreeNode* ans;
    pair<TreeNode*, int> getDeep(TreeNode* root, int depth)
    {
        if(!root)
            return {NULL, depth};
        auto l = getDeep(root->left, depth+1);
        auto r = getDeep(root->right, depth+1);
        if(l.second > r.second) //second value is depth
            return l;
        else if(r.second > l.second)
            return r;
        else
        {
            return {root, l.second};
            
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return root;
        // ans = NULL;
        auto p = getDeep(root, 0);
        // cout<<ans->val<<endl;
        return p.first;
    }
};