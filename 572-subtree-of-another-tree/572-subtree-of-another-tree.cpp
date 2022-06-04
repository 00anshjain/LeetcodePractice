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
    bool isSubTree(TreeNode* root, TreeNode* subRoot, bool flag) {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        // if(!subRoot)
        //     return false;
        if(subRoot->val == root->val)
        {
            // cout<<root->val<<" ";
            if(isSubTree(root->left, subRoot->left, true) && (isSubTree(root->right, subRoot->right, true)))
                return true;
        }
        if(flag == true)
            return false;
        return isSubTree(root->left, subRoot, false) || (isSubTree(root->right, subRoot, false));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return isSubTree(root, subRoot, false);
        // if(!root && !subRoot)
        //     return true;
        // if(!root || !subRoot)
        //     return false;
        // // if(!subRoot)
        // //     return false;
        // if(subRoot->val == root->val)
        // {
        //     cout<<root->val<<" ";
        //     if(isSubtree(root->left, subRoot->left) && (isSubtree(root->right, subRoot->right)))
        //         return true;
        // }
        // return isSubtree(root->left, subRoot) || (isSubtree(root->right, subRoot));
    }
};