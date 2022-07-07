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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Node* root = r;
        if(!root)
            return root;
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(!root->left)
        {
            return root->right;
        } 
        if(!root->right)
            return root->left;
        TreeNode* temp = root->right;
        TreeNode* temp2 = root->left->right;
        root = root->left;
        root->right = temp;
        while(temp->left != NULL)
            temp = temp->left;
        temp->left = temp2;
        return root;
        
        
    }
};