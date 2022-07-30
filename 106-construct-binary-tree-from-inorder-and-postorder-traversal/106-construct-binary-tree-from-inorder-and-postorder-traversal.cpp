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
    int idx;
    TreeNode* recur(vector<int>& in, vector<int>& post, int l, int r)
    {
        if(r < l)
            return NULL;
        if(r == l)
        {
            return new TreeNode(post[idx--]);
        }
        TreeNode* root = new TreeNode(post[idx--]);
        int m = l;
        while(m <= r)
        {
            if(in[m] == post[idx+1])
                break;
            m++;
        }
        root->right = recur(in, post, m+1, r);
        root->left = recur(in, post, l, m-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        idx = post.size() - 1;
        return recur(in, post, 0, idx);
        // return 
        
    }
};