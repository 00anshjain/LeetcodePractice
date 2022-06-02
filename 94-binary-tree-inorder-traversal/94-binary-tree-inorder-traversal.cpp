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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        // if(!root)
        //     return ans;
        // st.push(root);
        // root = root->left;
        while(!st.empty() || root)
        {
            if(!root)
            {   
                root = st.top();
                st.pop();
                ans.push_back(root->val);
                // if(root->right)
                root = root->right;
                // cout<<root->data;
            }
            else 
            // if(root->left)
            {
                st.push(root);
                root = root->left;
            }   
        }
        return ans;
    }
};