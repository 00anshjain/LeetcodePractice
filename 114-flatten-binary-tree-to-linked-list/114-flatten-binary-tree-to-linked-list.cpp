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
        stack<TreeNode*> st;
        TreeNode* head = root;
        while(root)
        {
            // cout<<root->val<<" ";
            if(!root->left && !root->right)
            {
                if(st.empty())
                {
                    root->right = NULL;
                    root = head;
                    return;
                }
                root->right = st.top();
                root = st.top();
                st.pop();
            }
            else if(!root->left)
            {
                root = root->right;
            }
            else
            {
                if(root->right)
                    st.push(root->right);
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
        root = head;
    }
};