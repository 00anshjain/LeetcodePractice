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
    TreeNode* recur(vector<int>& pr, vector<int>& in, int& idx, int l, int r)
    {
        if(r < l)
            return NULL;
        if(r == l)
        {
            idx++;
            return new TreeNode(in[l]);
        }
        TreeNode* root = new TreeNode(pr[idx++]);
        int m = l;
        while(m <= r)
        {
            if(in[m] == root->val)
            {
                root->left = recur(pr, in, idx, l, m-1);
                root->right = recur(pr, in, idx, m+1, r);
                return root;
            }
            m++;
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& pr, vector<int>& in) {
        int idx = 0;
        return recur(pr, in, idx, 0, in.size() - 1);
        
        
    }
};