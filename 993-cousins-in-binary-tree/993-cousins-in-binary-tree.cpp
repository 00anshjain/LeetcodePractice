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
    TreeNode* DFS(TreeNode* root, int x, int *ht)
    {
        if(!root)
            return NULL;
        if(root->val == x)
        {
            return root;
        }
        
        if(root->left && root->left->val == x)
        {
            // ht += 1;
            (*ht) += 1;
            return root;
        }
        if(root->right && root->right->val == x)
        {
            (*ht) += 1;
            return root;
        }
        // ht += 1;
        if(root->left)
        {
            (*ht) += 1;
            auto k = DFS(root->left, x, ht);
            if(k != NULL)
                return k;
            (*ht) -= 1;
        }
        if(root->right)
        {
            (*ht) += 1;
            auto k = DFS(root->right, x, ht);
            if(k != NULL)
                return k;
            (*ht) -= 1;   
        }
        return NULL;
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int h1 = 0, h2 = 0;
        TreeNode* a = DFS(root, x, &h1);
        TreeNode* b = DFS(root, y, &h2);
        // cout<<h1<<" "<<h2<<endl;
        return (a != b) && (h1 == h2);
    }
};