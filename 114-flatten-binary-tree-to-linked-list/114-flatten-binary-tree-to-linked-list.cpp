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
    void flatten(TreeNode* root) {
        TreeNode* head = root;
        if(!root)
            return;
        stack<TreeNode*> st;
        TreeNode* prev = NULL;
        while(!st.empty() || root)
        {
            if(!root)
            {
                root = st.top();
                st.pop();
            }
            // else
            // {
            if(root->right)
                st.push(root->right);
            // }
            if(prev)
            {
                prev->right = root;
                prev->left = NULL;
            }
            prev = root;
            root = root->left;
            
        }
        root = head;
    }
};